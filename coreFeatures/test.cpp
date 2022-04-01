#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

int main() {
	std::string str = "saad";
	std::vector<std::string> vec;
	std::cout << "after str: " << std::quoted(str) << "\n";

	vec.push_back(str);

	std::cout << "after normal push_back:" << std::quoted(str) << "\n";
	vec.push_back(std::move(str));
	std::cout << "after move push_back: " << std::quoted(str) << "\n";
	return 0;
}
