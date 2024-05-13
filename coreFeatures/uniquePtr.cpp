// raw poiinters allow sharing. uniq ptr are scoped pointers means itll delete
// itself.
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;
void raw_pointer() {
  int x = 42;
  int *ptr = &x;
  std::cout << "ptr: " << ptr << "\n";
  std::cout << "*ptr: " << *ptr << "\n";
  int *ptr2 = ptr;
  std::cout << "ptr2: " << ptr2 << "\n";
  std::cout << "*ptr2: " << *ptr2 << "\n";
}

void raw_pointer2() {
  int *array = new int[100];
  for (int i = 0; i < 100; i++) {
    array[i] = i + 1;
  }
  int *ptr = array;
  std::cout << "*ptr = " << *ptr << "\n";
  delete[] array;

  float *new_array = new float[100];
  int *ptr2 = ptr;
  std::cout << "*ptr2 = " << *ptr2
            << "\n"; // pointing to already deleted mem. cpp runtime is smart,
                     // it doesnt crash and give you 0 as opt. smart pointers
                     // address these issues about ownership
}

/*
 * Can not share (no copies are allowed)
 * Do not have to delete
 */
class UDT {
public:
  UDT() { std::cout << "UDT created \n"; }
  ~UDT() { std::cout << "UDT destroyed \n"; }
};

// custom smart pointer.
class MyInt {
public:
  MyInt(int *p) { data = p; }
  ~MyInt() { delete data; }
  int &operator*() { return *data; }

private:
  int *data;
};

/*
int main() {
//	raw_pointer();
//	raw_pointer2();
        //UDT obj;
//	std::unique_ptr<UDT> obj2;
//	std::unique_ptr<UDT> obj3 = std::unique_ptr<UDT>(new UDT);
//	std::unique_ptr<UDT[]> obj4 = std::unique_ptr<UDT[]>(new UDT[10]);
//initalizing array std::unique_ptr<UDT[]> obj5 = std::make_unique<UDT[]>(2);
//easy alternative syntax

        int* p = new int(10); //initialized with value 10
        std::cout << p << "\n";// --> addres
        std::cout << *p << "\n"; // --> 10
        MyInt myint = MyInt(p);
        std::cout << *myint << std::endl; //* is overloaded/
        return 0;
}
*/

// Bo Qian lesson

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

// Unique ptr represents exclusive membership of object. its lightweight ptr so
// its less expensive than shared ptr

void foo() {
  unique_ptr<Dog> p1(new Dog("Gunner"));
  unique_ptr<Dog> p2(new Dog("Smokey"));
  p2->bark();
  p2 = move(p1); // 1. Smokey is destroyed 2. p1 becomes empty 3. p2 owns Gunner
  p2->bark();
}

void transfer_ownership(unique_ptr<Dog> p) { p->bark(); }

void test_transfer_ownership() {
  unique_ptr<Dog> p1(new Dog("Gunner"));
  transfer_ownership(move(p1));
  // Question: where is Gunner destroyed? inside test func or inside
  // transfer_ownership? its destoyed inside transfer_ownership func becuase we have moved it there
  if(!p1) {
	cout << "p1 is empty\n";
  }
}

int main() { test_transfer_ownership(); }