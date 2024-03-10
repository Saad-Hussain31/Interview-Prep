/*
the purpose of this program is to show how clean extensibility can and should
be.

case sensitivity a property of the object may not always be the best
approach.For instance, consider the scenario where you have two different types
of strings: ci_string (case-insensitive) and yz_string (using a custom
comparison). In this scenario, if you have an expression like b == c, where b is
a ci_string and c is a yz_string, it's unclear whether the comparison should be
case-insensitive or follow the custom comparison logic of yz_string.

Instead of making case sensitivity a property of the object, it can be more
useful to have it as a characteristic of the comparison operation.


*/
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

struct ci_char_traits : public char_traits<char> {
  static bool eq(char c1, char c2) { return toupper(c1) == toupper(c2); }

  static bool lt(char c1, char c2) { return toupper(c1) < toupper(c2); }

  // Both strings are equal up to 'n' characters
  static int compare(const char *s1, const char *s2, size_t n) {
    for (size_t i = 0; i < n; ++i) {
      int result = std::toupper(s1[i]) - std::toupper(s2[i]);
      if (result != 0)
        return result;
    }
    return 0;
  }

  static const char *find(const char *s, int n, char a) {
    while (n-- > 0 && std::toupper(*s) != std::toupper(a)) {
      ++s;
    }
    return n >= 0 ? s : nullptr;
  }
};

using ci_string = std::basic_string<char, ci_char_traits>;

int main() {
  ci_string s("AbCdE");
  assert(s == "abcde");
  assert(s == "ABCDE");
  assert(strcmp(s.c_str(), "AbCdE") == 0);
  assert(strcmp(s.c_str(), "abcde") != 0);
  return 0;
}
