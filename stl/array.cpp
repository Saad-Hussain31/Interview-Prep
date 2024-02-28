/*
STL = containers + iterators + algorithms

std::array<T,N> arr;

why std::array?
encapsulates fixed sized array.
arraysize is needed at compile time. 
assign by value is actually by value (a copy is passed, not ref). no ptr passing when passing to functions.
assingning using initializer list is possible
Access elements: at(), [], front(), back(), data()
why have both at() and []? coz at() is bounded function means itll throw out of bound exception when u try to access mem that doesnt exist. [] will give garbage
front() gives first and back() gives last.
data() gives access to underlying array
fill() is when u wanna assign some typical value to entire array.

*/


#include <iostream>
#include <array>

using namespace std;

int main() {
    
    array<int, 5> arr {1,2,3,4,5};

    array<int, 6> arr2; 
    arr2 = {1,2,3,4,5,6}; //init using init list.
    return 0;

}