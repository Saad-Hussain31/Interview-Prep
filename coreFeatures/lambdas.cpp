#include <iostream>
#include <functional>
#include <vector>


using namespace std;

void for_each(const std::vector<int>& values, void(*func)(int)) {
    for(int val : values) {
        func(val);
    }
}

void print(int value) {
    cout << "Print() called and value is: " << value << endl;
}


int main() {
        
    // typedef void(*f2ptr)(int);
    // f2ptr bar = print;
    // bar(7);

    // auto f = &print;      
    // void(*fptr)(int) = print; //this is the actual type of auto above

    std::vector<int> v {1,5,4,6};
    for_each(v, print);

    auto lambda = [](int val) { 
        cout << "lambda called and value is: "<< val << endl;
    };
    for_each(v, lambda);


    for_each(v, [](int val) { 
        cout << "lambda called and value is: "<< val << endl;
    }); //another way of calling lambda without assign to an obj

    return 0;
}