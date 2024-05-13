#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

using namespace std;

mutex gLock;
static int sharedValue{0};

void sharedValueIncr() {
  gLock.lock();

  try {
    sharedValue += 1;
    cout << "Value is: " << sharedValue << endl;
    // throw "lmao"; //if exception is thrown then we have to unlock in catch
    // block
  } catch (...) {
    cout << "handle exp\n";
    gLock.unlock();
  }

  gLock.unlock(); // also have to unlock here (for if exp is not thrown and flow
                  // executes normally. this makes code convuluted. use
                  // lock_guard (RAII))
}

void sharedValueIncrUsingRAII() {
  lock_guard<mutex> lock(gLock);

  try {
    sharedValue += 1;
    cout << "Value is: " << sharedValue << endl;
  } catch (...) {
    cout << "handle exp\n";
  }
}

int main() {
  vector<thread> thds;
  for (int i = 0; i < 100; ++i) {
    // thds.push_back(thread(sharedValueIncr));
    thds.push_back(thread(sharedValueIncrUsingRAII));
  }

  for (int i = 0; i < 100; ++i) {
    thds[i].join();
  }
  return 0;
}