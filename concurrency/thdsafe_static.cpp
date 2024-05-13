#include <atomic>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

using namespace std;

static int s = 0;

void func() {
    int count = 1000;
    while(count--) {
        ++s;
    }
    cout << s << endl;
}

int main() {
    thread t1(func);
    thread t2(func);
    t1.join();
    t2.join();
    return 0;
}