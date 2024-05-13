#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Dog {
  string mName;
  weak_ptr<Dog>
      mFriend; // I want to access the object only, dont want ownership. When
               // and how the object will be deleted is none of my business
               // having a weak ptr is like having a raw ptr except it doesnt
               // allow delete to be called.

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

  // lock() creates shared ptr out of weka ptr to check if weak ptr is
  // pointing to a valid object and to make sure while its accessing the
  // object, the obj wont be deleted.
  void showFriend() {
    if (!mFriend.expired()) { // safety check: if weakptr is not pting to valid
                              // object then lock return nullptr which should be
                              // checked beforehand
      cout << "My friend is: " << mFriend.lock()->mName << endl;
      cout << "He is owned by " << mFriend.use_count() << "ptrs" << endl;
    }
  }
};

void cyclic_reference() {
  shared_ptr<Dog> p1(new Dog("Gunner"));
  shared_ptr<Dog> p2(new Dog("Smokey"));
  p1->makeFriend(p2);
  p2->makeFriend(p1);
}

void using_weak_ptrs_apis() {
  shared_ptr<Dog> p1(new Dog("Gunner"));
  shared_ptr<Dog> p2(new Dog("Smokey"));
  p1->makeFriend(p2);
  p2->makeFriend(p1);
  p1->showFriend();
}

int main() {
  //   cyclic_reference();
  using_weak_ptrs_apis();
}