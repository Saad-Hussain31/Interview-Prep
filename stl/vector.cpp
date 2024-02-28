/*
vector = array + list

sequence cont aka dynamic array or array list
its size can grow and shrink dyn and no need to give size at compile time.

why need array? for fast access. O(1) but cant grow dynamically for eg when building a tree
why need linked list? coz can grow dyn. vector is combination of both

modifiers: emplace_back(), resize(), swap() , erase(), clear()

*/

#include <iostream>
#include <vector>
using namespace std;

void documentation() {
    vector<int> vec(5,20); //create vector of size 5 and fill it with 20s
    vec[2] = 10;
    vec.at(3) = 10; //exception safe
}

void cost_of_copy() {
    vector<int> vec;
    for(int i=0; i < 32; ++i) {
        vec.push_back(i);
        cout << "Size: " << vec.size() << " Capacity: " << vec.capacity() << endl;
    }
    //every time capacity is double, a new array under the hood is getting created and prev one is copied in it
    // to avoid this use reserver()
}

void using_reserve() {
    vector<int> vec;
    vec.reserve(1000);
    for(int i=0; i < 32; ++i) {
        vec.push_back(i);
        cout << "Size: " << vec.size() << " Capacity: " << vec.capacity() << endl;
    }    

}

int main() {

    // cost_of_copy();
    using_reserve();

}