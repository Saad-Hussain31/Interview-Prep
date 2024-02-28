/*
Generics 5: variadic args and variadic function templates. (through parameter pack)
Why use this? say u wanna write your own printf to print different things out


*/

#include <iostream>
using namespace std;

//think of it like a base case
template <typename T>
T sum(T arg) {
    return arg;
}


template<typename T, typename... Args>
T sum(T start, Args... args) { 
    return start + sum(args...); //calls base case.  
}

int main() {
    cout << sum(1,2,3,4) << endl;
    cout << sum(1,2.2f,3.7,4,5) << endl;
    return 0;
}