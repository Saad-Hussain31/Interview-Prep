#include <thread>
#include <iostream>
#include <mutex>
#include <vector>


static int shared_value = 0;
std::mutex lk;

void shared_value_incr() {
    lk.lock();
    shared_value = shared_value + 1;
    lk.unlock();
}


std::mutex mu;
void print_msg(std::string msg, int id) {
    mu.lock();
    std::cout << msg << id << std::endl; //if this throws then mu wont get unlocked. so use lock_guard
    mu.unlock();
}

void function_1() {
    for(int i=0; i>-100; --i) {
        print_msg(std::string("From t1: "), i);
    }
}

int main() {

    // std::vector<std::thread> thds;
    // for(int i=0; i<100; ++i) {
    //     thds.push_back(std::thread(shared_value_incr));
    // }

    // for(int i =0; i<100; ++i) {
    //     thds[i].join();
    // }

    // std::cout << "Shared value: " << shared_value << std::endl;

    std::thread t1(function_1);
    for(int i=0; i<100; ++i) {
        // std::cout << "From main: " << i << std::endl; 
        print_msg(std::string("From main: "), i);
    }

    t1.join();

    return 0;
}