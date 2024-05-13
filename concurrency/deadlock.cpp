#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

using namespace std;

mutex gLock;
static int sharedValue{0};

void sharedValueIncr() { 
    gLock.lock();
    sharedValue += 1;
    cout << "Value is: " << sharedValue << endl;
    gLock.unlock();
}


int main() {
  vector<thread> thds;
  for (int i = 0; i < 100; ++i) {
    thds.push_back(thread(sharedValueIncr));
  }

  for (int i = 0; i < 100; ++i) {
    thds[i].join();
  }
  return 0;
}