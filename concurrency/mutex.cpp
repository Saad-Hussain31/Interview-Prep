#include <thread>
#include <iostream>
#include <mutex>
#include <vector>


static int shared_value = 0;


void shared_value_incr() {
    shared_value = shared_value + 1;
}

int main() {

    std::vector<std::thread> thds;
    for(int i=0; i<100; ++i) {
        thds.push_back(std::thread(shared_value_incr));
    }

    for(int i =0; i<100; ++i) {
        thds[i].join();
    }

    std::cout << "Shared value: " << shared_value << std::endl;
}