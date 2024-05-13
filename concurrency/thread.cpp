/*
threads contains separate SP and PC but share libs, runtime heap, data.
MT pros: fast to start, low over head
communication with shared memory is faster than IPC channels
Cons: difficult to implement
MT cant run on dist systems, for that to work, use IPC instead of SM.

join() will wait for thread t on main() and then exit
detach() will make t run independently of calling thd (main in this case). t
becomes daemon process.so main can exit and t will still be running and itll be
C++ runtimes job to reclaim the resources acquired by t.

if main and t are sharing resources, in this case cout, then calling (main thd)
should exists until t stops using the resource

join or detach can be done only once. use joinable() to prevent crashes.

thd management can be done via try catch block.

*/

#include <iostream>
#include <thread>
#include <vector>
using namespace std;
/*
// thread 1:mike shah

void test(int x) {
  std::cout << "Hello from thd\n";
  std::cout << "arg passed: " << x << std::endl;
}

int main() {

  std::thread thd(&test, 100);
  thd.join(); // join will wait until test() completes. detach() wont wait itll
              // just continue

  std::cout << "Hello from main thd\n";

  std::thread thd2([]() { std::cout << "lmao" << std::endl; });
  thd2.join();
  return 0;
}
*/

int main() {
  auto lambda = []() {
    cout << "Hello from thread " << this_thread::get_id() << endl;
  };

  vector<thread> thds;
  for (int i = 0; i < 10; ++i) {
    thds.push_back(std::thread(lambda));
    // thds[i].join(); 
  }

  for (int i = 0; i < 10; ++i) {
    thds[i].join();
  }
  cout << "Hello from main thd\n";
  return 0;
}