#include <iostream>
#include <ostream>

class Vector {
public:
  Vector() {
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
  }

  Vector operator+(const Vector &rhs) const { //
    Vector result;
    result.x = x + rhs.x;
    result.y = y + rhs.y;
    result.z = z + rhs.z;
    return result;
  }

  Vector operator++() {
    x = x + 1;
    y = y + 1;
    z = z + 1;
    return *this;
  }

  float x, y, z;
};

std::ostream &operator<<(std::ostream &os, const Vector &obj) {
  os << obj.x << "," << obj.x << "," << obj.z;
  return os;
}

int main() {

  Vector vec1;
  vec1.x = 1.0f;
  vec1.y = 2.0f;
  vec1.z = 3.0f;

  Vector vec2;
  vec2.x = 3.0f;
  vec2.y = 2.0f;
  vec2.z = 1.0f;

  vec1 = vec1 + vec2;

  ++vec1;

  //   std::cout << vec1.x << "," << vec1.y << "," << vec1.z << std::endl;
  std::cout << vec1 << std::endl;

  return 0;
}