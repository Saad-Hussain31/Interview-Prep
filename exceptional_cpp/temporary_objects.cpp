#include <iostream>
#include <list>
#include <string>

// Define the Employee class
class Employee {
private:
    std::string name;
    std::string addr;

public:
    Employee(const std::string& name, const std::string& addr) : name(name), addr(addr) {}

    std::string getName() const {
        return name;
    }

    std::string getAddress() const {
        return addr;
    }
};

// Define the FindAddr function
std::string FindAddr(const std::list<Employee>& emps, const std::string& name) {
    for (const auto& emp : emps) {
        if (emp.getName() == name) {
            return emp.getAddress();
        }
    }
    return ""; // Return an empty string if address not found
}

int main() {
    // Create a list of employees
    std::list<Employee> employees;
    employees.emplace_back("John Doe", "123 Main St");
    employees.emplace_back("Jane Smith", "456 Elm St");

    // Find the address of an employee
    std::string nameToFind = "John Doe";
    std::string address = FindAddr(employees, nameToFind);

    if (!address.empty()) {
        std::cout << "Address of " << nameToFind << " is: " << address << std::endl;
    } else {
        std::cout << "Address not found for " << nameToFind << std::endl;
    }

    return 0;
}
