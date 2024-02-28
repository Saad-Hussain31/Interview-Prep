/*
std::set<T> set1;

1 associative container contains sorted set of unique objects of key T.
1.2 multiset is an associative container contains sorted set of duplicate objects of key T.
2 usually implemented using red black tree
3 insertion, removal, search have log complexity(coz its a tree)
4 if u wanna store UDTs in set then provide compare functions so that set can store them in sorted order
5 we can pass the order of sorting while constucting the set obj


*/

#include <iostream>
#include <set>
#include <functional>

using namespace std;


void using_set() {
    set<int> set = {1,2,5,4,3,1,2,3,4,5};
    //if wanna store data in desc order then set<int, std::greater> set; by default its std::less
    for(const auto& e : set ) {
        cout << e << endl;
    }
}

class Person {
public:
    int age;
    string name;
    //set does not know what a Person is and hence it cant compare 2 persons. u gotta provide compare func
    bool operator <(const Person& rhs) const {
        return age < rhs.age;
    }

    bool operator >(const Person& rhs) const {
        return age > rhs.age;
    }
};

int main() {
    set<Person, std::greater<>> set1 = {{25, "saad"}, {26, "hussain"}}; //desc order 

    for(const auto& e : set1) {
        cout << e.age << " " << e.name << endl;
    }

    return 0;
}