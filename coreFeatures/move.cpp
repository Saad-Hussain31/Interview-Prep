//think of it as stealing the resources from 1 object to another. moving the data i.e transfering the ownership.

#include <iostream>
#include <string>
#include <vector>



int main() {

	std::string myString = "copy construct me";
	std::string newValue;

	std::cout << "myString: " << myString << "\n";
	std::cout << "newValue: " << newValue << "\n";

	//newValue = std::move(myString); // resource transfered
	//newValue = myString; //resource copied
	newValue = static_cast<std::string&&>(myString); //same as std::move


	std::cout << "myString: " << myString << "\n";
	std::cout << "newValue: " << newValue << "\n";
}
