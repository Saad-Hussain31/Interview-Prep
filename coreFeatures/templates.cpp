/*
avoid copy paste
serve as blueprint for compiler to generate code
full specialization is filling in every single template parameter, and partial is setting at least one but not all paramters

*/

#include <iostream>

template <typename T> T square(T input) { return input * input; }

// generics 2
// abbrevuated fucntion template(C++20): achieving same thing but by using auto
// auto sqaure2(auto input) {
//     return input * input;
// }

// generics 3 multiple template params
template <typename T1, typename T2> void foo(T1 input1, T2 input2) {
  std::cout << input1 << std::endl;
  std::cout << input2 << std::endl;
}



int main() {
  //   std::cout << square(5) << std::endl;
  //   std::cout << square(5.5) << std::endl;
  //   std::cout << square(6.5f) << std::endl;

//   foo<int, double>(5, 3.14);




}