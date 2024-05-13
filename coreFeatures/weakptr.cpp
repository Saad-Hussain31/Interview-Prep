#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Dog {
  string mName;
  shared_ptr<Dog> mFriend;

public:
  Dog(string name) {
    cout << "Dog is created " << name << endl;
    mName = name;
  }

  Dog() {
    cout << "Nameless dog is created " << endl;
    mName = "nameless";
  }

  ~Dog() { cout << "Dog is destroyed " << mName << endl; }

  void bark() { cout << "Dog " << mName << " rules!" << endl; }

  void makeFriend(shared_ptr<Dog> f) { mFriend = f; }
};


void cyclic_reference() {
    shared_ptr<Dog> p1(new Dog("Gunner"));
    shared_ptr<Dog> p2(new Dog("Smokey"));
    p1->makeFriend(p2);
    p2->makeFriend(p1);
}

int main() {
    cyclic_reference();
}