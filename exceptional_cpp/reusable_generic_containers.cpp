/*
template constructor is never a copy constructor, the presence of such a
template does not suppress the implicit declaration of a copy constructor.

compiler still generates the implicit versions. What we've done is extend the
construction and assignment flexibility, not replace the old versions.

*/

#include <iostream>
#include <vector>
using namespace std;

template <typename T, size_t size> class fixed_vector {
public:
  typedef T *iterator;
  typedef const T *const_iterator;

  fixed_vector() {}

  template <typename O, size_t osize>
  fixed_vector(const fixed_vector<O, osize> &other) {
    copy(other.begin(), other.begin() + min(size, osize), begin());
  }

  template <typename O, size_t osize>
  fixed_vector<T, size> &operator=(const fixed_vector<O, osize> &other) {
    copy(other.begin(), other.begin() + min(size, osize), begin());
    return *this;
  }

  T &operator[](size_t index) { return v_[index]; }

  iterator begin() { return v_; }
  iterator end() { return v_ + size; }
  const_iterator begin() const { return v_; }
  const_iterator end() const { return v_ + size; }

private:
  T v_[size];
};

int main() {
  fixed_vector<int, 5> vec1;
  vec1[0] = 1;
  vec1[1] = 2;
  vec1[2] = 3;
  vec1[3] = 4;
  vec1[4] = 5;

  fixed_vector<double, 3> vec2;
  vec2[0] = 1.1;
  vec2[1] = 2.2;
  vec2[2] = 3.3;

  fixed_vector<int, 5> vec3 = vec1;    // Templated copy constructor usage
  fixed_vector<double, 3> vec4 = vec2; // Templated copy constructor usage

  fixed_vector<int, 5> vec5;
  vec5 = vec3; // Templated copy assignment operator usage

  for (const auto &elem : vec5) {
    cout << elem << " ";
  }

  return 0;
}
