/*
threads contains separate SP and PC but share libs, runtime heap, data.


*/


#include <thread>
#include <iostream>


void test(int x) {
    std::cout << "Hello from thd\n";
    std::cout << "arg passed: " << x << std::endl;
}

int main() {

    std::thread thd(&test,100);
    thd.join(); //join will wait until test() completes. detach() wont wait itll just continue

    std::cout << "Hello from main thd\n";


    std::thread thd2([]( ) {
        std::cout << "lmao" <<  std::endl;
    });
    thd2.join();
    return 0;
}