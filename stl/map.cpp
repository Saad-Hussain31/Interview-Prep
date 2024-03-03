/*
std::map<T1, T2> obj;

1 associative container store elements as key and values where key should be unique otherwise it overrides
2 implemented using self balance binary search tree (AVL/ red black tree)
3 for udt, provide compare functions

*/

#include <iostream>
#include <map>
#include <vector>
#include <functional>

using namespace std;

void simple_map() {
    map<string, int> map1;// use std::greater<> for desc order
    map1["saad"] = 90238409;
    map1["hussain"] = 8237462;
    map1.insert(std::make_pair("bot", 237984)); //map1.insert({"bot", "238744"});

    for(auto &e : map1) {
        cout << e.first << " " << e.second << endl;
    }

    // cout << map1["saad"] << endl; //print value associated with key "saad"
}

void key_multiple_values() {
    map<string, vector<int>> map1;
    map1["saad"].push_back(2348);
    map1["hussain"].push_back(234987);
    map1["hussain"].push_back(6969696);
    for(auto &e : map1) {
        cout << e.first  << endl;
        for(auto &e1 : e.second) {
            cout << e1 << " ";
        }
        cout << endl;
    }
}

int main() {

    key_multiple_values();
    return 0;
}