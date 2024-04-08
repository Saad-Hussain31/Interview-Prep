/*
for this to work, need at least 2 threads. this is somewhat like the producer
consumer problem. need a boolean var, a lock, CV, 2 thds (worker and reporter).

reporter thd will wait to be notified by worker thd. while waiting it willl just
sleep which saves thd spinning time.

wait() blocks the current thd until the CV is woken up

notify_one() notifies one waiting thd

worker thd will do its job first no matter which one you start first.



*/

#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

std::mutex gLock;
std::condition_variable gConditionVariable;

int main() {

  int result = 0;
  bool notified = false;

  std::thread reporter([&] {
    std::unique_lock<std::mutex> lock(gLock);
    if (!notified) {
      gConditionVariable.wait(lock);
    }
    std::cout << "Reporter, result is: " << result << std::endl;
  });

  std::thread worker([&] {
    std::unique_lock<std::mutex> lock(gLock);
    result = 234 + 5334;
    notified = true;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Work complete\n";
    gConditionVariable.notify_one();
  });
  reporter.join();
  worker.join();
  return 0;
}