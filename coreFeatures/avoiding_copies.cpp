/*
The core idea of this code is to have const reference when the function is
taking a object of type T. Doing this will prevent unnecessary object copy
creation.
*/

#include <iostream>
#include <vector>

class Array {
public:
  Array() {
    std::cout << "Ctor" << std::endl;
    for (int i = 0; i < 1000000; ++i) {
      data.push_back(i);
    }
  }

  ~Array() {}

  // copy ctor.
  Array(const Array &rhs) {
    std::cout << "Copy Ctor" << std::endl;
    for (int i = 0; i < rhs.data.size(); ++i) {
      data.push_back(rhs.data[i]);
    }
  }

  // Copy assignment operator
  // obj already constructed. we are just copying later
  // ie. arr2 = arr;
  Array &operator=(const Array &rhs) {
    std::cout << "Copy assignment operator" << std::endl;
    if (&rhs == this) {
      return *this;
    }
    data.clear();
    for (int i = 0; i < rhs.data.size(); ++i) {
      data.push_back(rhs.data[i]);
    }
    return *this;
  }

  void print_data() {
    for (int i = 0; i < data.size(); ++i) {
      std::cout << data[i] << std::endl;
    }
  }

  void set_data(int idx, int val) { data[idx] = val; }

private:
  std::vector<int> data;
};

// if the input param were not const ref then many copies would have been
// created which is not desired
void print_an_array(const Array &a) {
  // a.print_data();
}

int main() {
  Array arr;

  arr.set_data(0, 1234567);

  Array arr2 = arr; // copy ctor called

  arr.print_data();
  arr2.print_data();

  print_an_array(arr);
}
