/*

static outside class means that the
scope is limited to the transalation unit/binary in which it is created. its
kinda like declaring a member private in the class. the linker doesnt see it.


static in class means for all instances of a class, there will be only 1
instance of the var thats declared static.

Static member functions call only access static vars. cant access the nonstatic
ones because all nonstatic member func takes instance of class as hidden
param(self in python). a static member function does not get that hidden instan
as param. since it doesnt have the instance, it cant call/access the member vars
of that class.

----------------------------
Static for Classes and Structs:

call with :: operator. no need to create instance.


*/

#include <iostream>

using namespace std;

struct Entity {
  static int x; // only 1 inst of static vars across all insts of Entity class
  static int y;

  static void PrintEntity() {
    cout << x << "," << y << endl;
  } // doesnt get hidden class inst as param thats why it can access x and y cz
    // they are also not class members.
};

int Entity::x; // you can get rid of this definition by using c++17 inline usage
               // when declaring static data inside class
int Entity::y;

int main() {

  Entity::x = 5;
  Entity::y = 8;

  Entity::PrintEntity();
}