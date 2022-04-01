/*
 * 2 pointers can point to same resource.  
 * when all ptrs get freed, the destructor will be auto called.
*/
#include <iostream>
#include <string>
#include <vector>
#include <memory>

class UDT {
public: 
    UDT() { std::cout << "UDT Created \n";}
    ~UDT() { std::cout << "UDT destroyed\n" ;}
};

int main() {

    std::shared_ptr<UDT> ptr = std::make_shared<UDT>(); //ptr is pointing to a resource
    {
        std::shared_ptr<UDT> ptr2 = ptr; // ptr2 is pointing to same above resource. hence the resource is shared by 2 pointers. wasnt allowed with unique ptr. 
        std::cout << "reference count = " << ptr2.use_count() << "\n";//after this line, scope of ptr2 is destroyed
    }
    // std::cout << "reference count = " << ptr2.use_count() << "\n";// error coz ptr2 no longer exist.
    std::cout << "reference count = " << ptr.use_count() << "\n";
    
    
    return 0;
}