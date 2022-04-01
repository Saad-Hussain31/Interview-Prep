#include <string>
#include <iostream>
// lvalueL: something with a memory location. eg: &(i) 
// rvalue: on the RHS of assignment.  Doesnt point anywhere.
int rvalue_demo() {
	int a = 5;
	int b = 10;
	int c = (a+b); //(a+b) is also rvalue becz we cant take it's address. also call xvalue for expiry(temporary) value
	return 0;
}

//lvalue ref is just an & 
void lvalue_reference_demo() {
	int i = 10;
	int& ref = i;

	//int& ref2=10; //within lvalue reference, i cant refer to rvalue.
	const int& ref3 = 10;
}
int set_to_99(int& change_me) {
	change_me = 99;
	return change_me;
}

void rvalue_reference_demo() {
	std::string s1 = "saad";
	std::string s2 = "hussain";
	std::string s3 = s1 + s2; //rhs will frst get evaluated which is overhead, so instead.
	std::string&& s4 = s1 + s2; //no evaluation
	int&& s5 = 5+5; 
}

int main() {
	int i = 10;
	std::cout << set_to_99(i) << "\n";
	
//	set_to_99(10); //error
	return 0;
}
