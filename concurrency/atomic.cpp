#include <atomic>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

using namespace std;

static std::atomic<int> sharedValue{0};

void sharedValueIncr() { sharedValue++; }

int main() {
  vector<thread> thds;
  for (int i = 0; i < 1000; ++i) {
    thds.push_back(thread(sharedValueIncr));
  }

  for (int i = 0; i < 1000; ++i) {
    thds[i].join();
  }

  cout << "shared value is: " << sharedValue << endl;
}
