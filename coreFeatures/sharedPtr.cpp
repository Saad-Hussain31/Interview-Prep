/*
 * 2 pointers can point to same resource.
 * when all ptrs get freed, the destructor will be auto called.
 */
#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;
class UDT {
public:
  UDT() { std::cout << "UDT Created \n"; }
  ~UDT() { std::cout << "UDT destroyed\n"; }
};

/*

int main() {

    std::shared_ptr<UDT> ptr = std::make_shared<UDT>(); //ptr is pointing to a
resource
    {
        std::shared_ptr<UDT> ptr2 = ptr; // ptr2 is pointing to same above
resource. hence the resource is shared by 2 pointers. wasnt allowed with unique
ptr. std::cout << "reference count = " << ptr2.use_count() << "\n";//after this
line, scope of ptr2 is destroyed
    }
    // std::cout << "reference count = " << ptr2.use_count() << "\n";// error
coz ptr2 no longer exist. std::cout << "reference count = " << ptr.use_count()
<< "\n";


    return 0;
}
*/

// Bo Qian Shared Pointer Lesson

/*
the real problem with raw ptrs is with delete keyword. if we delete the ptr
early then we have dangling ptr and if we forget to delete it then we have a
memory leak.



*/

class Dog {
  string mName;

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
};

void foo() {
  //   Dog *p = new Dog("Gunner");
  //   //...
  //   delete p;
  //   //..
  //   p->bark(); // p is a dangling ptr -- undefined behavior

  shared_ptr<Dog> p1(
      new Dog("Gunner")); // keep tracks of how many shared ptrs are pointing to
                          // the obj. currently, count = 1
  {
    shared_ptr<Dog> p2 = p1; // p2 is also pointing to Gunner. count =2
    p2->bark();
  }
  // count = 1
  p1->bark();
} // count = 0

int main() {
  foo();

  Dog *d = new Dog("Tank");
  shared_ptr<Dog> p(
      d); // p.use_count == 1  when p goes outta scope Tank will be destroyed
  shared_ptr<Dog> p2(d); // p2.use_count == 1 when p2 goes outta scope, Tank
                         // will be destroyed again. undef behav.
  // so key about using shared ptr is that obj should be assinged to smart ptr,
  // as soon as it is created. raw ptrs shoudlnt be used again.
}