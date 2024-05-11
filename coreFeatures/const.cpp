/*
const: a compile time constraint that an obj cant be modified

If const is on left of *, data is const

If const is on right of *, ptr is const

Self documenting

enable compiler optimizaation

const means the variable can be put in ROM //used in embedded
*/




#include <iostream>
#include <vector>


int main() {
    const int i = 9;

    const int *p1 = &i; // data is const, pointer is not

    p1++; //OK: coz modifying p1, not the data stored at p1

    // int* const p2; //ptr is const, data is not
    
    // const int* const p3; //both data and ptr are const


}