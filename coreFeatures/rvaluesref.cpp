/*
lvalueL: something with a memory location. IOW anything I can take address of(&) eg: &(i) 
rvalue: on the RHS of assignment.  Doesnt point anywhere means I cant take address of
the main usage of r and lvals is to do with the optimization. if we know that an obj is temp obj than we can 'steal' iow use its resources to use somewhere else
which we could not do with consts 

std::string foo(const std::string& str); cant steal coz could be used other places
std::string bar(std::string&& str); can steal str's resources coz its temp obj
*/


#include <string>
#include <iostream>

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

	const int& ref3 = 10; //compiler creates a temp var, stores 10 in it and then take reference in ref3
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
	int i = 10; // i is lval coz it exists in a mem loc. 
	std::cout << set_to_99(i) << "\n";
//	set_to_99(10); //error

	return 0;
}
