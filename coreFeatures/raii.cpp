/*
why raii? Resource Management: say an exception is thrown then how are you gonna delete the obj? thru dtor which is exactly what raii is.

In C based code, the libs provide separate funcs for allocs and deallocs like in SDL these ops have separate funcs. in C++ using SDl, write a class with
ctor and dtor that uses theses fuinctions for resource mamagement.
*/

#include <iostream>

using namespace std;

int main() {
    int* Collection = new int[10];
    Collection[0] = 7; //40 bytes leaked. solution? make a class and write ctor and dtor.
    return 0;
}