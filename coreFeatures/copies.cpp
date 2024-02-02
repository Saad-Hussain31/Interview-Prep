/*
Copy ctor: Vector3 vec2 = vec1; 
Copy asgn: Vector3 vec;
           vec = vec1;

- For primitive types, when we create a class, C++ gives us default (compiler generated) ctor, dtor, copy ctor & copy assignment operator, but
it does the shallow copy. ie. arr2.data = arr.data; //here compiler doesnt create or allocate new mem for arr2's data member, it simply makes 
it point to arr's data. 

- This leads to double free mem issue which means that youre trying to delete(via dtor) the memory of "both" arr and arr2, but they are the same mem.

- So whenever you have ptrs or doing dyn mem alloc (malloc, calloc) always write your own copy ctor -> Deep copy.

- Good idea to provide a ctor so that you have control. 

*/


#include <iostream>
#include <string>

class Array {
public:
    Array() {
        std::cout << "Ctor" << std::endl;
        data = new int[10];
        for(int i = 0; i<10; ++i) {
            data[i] = i * i;
        }
    }

    ~Array() {
        delete[] data;
    }

    //copy ctor. this does deep copy from arr to arr2. now arr2 has its own mem, not the copy of arr
    Array(const Array& rhs) {
        std::cout << "Copy Ctor" << std::endl;
        data = new int[10];
        for(int i = 0; i < 10; ++i) {
            data[i] = rhs.data[i];
        }
    }

    //Copy assignment operator
    //obj already constructed. we are just copying later
    // ie. arr2 = arr;
    Array& operator=(const Array& rhs) {
        std::cout << "Copy assignment operator" << std::endl;
        if(&rhs == this) {
            return *this;
        } 
        delete[] data;
        data = new int[10];
        for(int i = 0; i < 10; ++i) {
            data[i] = rhs.data[i];
        }
        return *this;
    }

    void print_data() {
        for (int i = 0; i < 10; ++i) {
            std::cout << data[i] << std::endl;
        }
    }

    void set_data(int idx, int val) {
        data[idx] = val;
    }
private:
    int* data;
};


int main() {
    Array arr;
    
    //setting data for arr only(not for arr2)
    arr.set_data(0,10000);
    arr.set_data(1,77);
    arr.set_data(2,999);

    // Array arr2 = arr; //copy ctor is called
    // fresh clone and run will give copy asg operator example.
    //too see copy ctor run, uncomment above line & comment below 2 lines. 

    Array arr2;
    arr2 = arr; //copy asg operator is called

    arr.print_data();
    arr2.print_data();
}
