#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

bool isPalindrome(string s) {
  int i = 0;
  int j = s.size() - 1;

  while (i < j) {
    while (!isalnum(s[i]) && i < j) {
      i++;
    }
    while (!isalnum(s[j]) && i < j) {
      j--;
    }
    if (tolower(s[i]) != tolower(s[j])) {
      return false;
    }
    i++;
    j--;
  }

  return true;
}

int main() {
  assert(isPalindrome("A man, a plan, a canal, Panama") == true);
  assert(isPalindrome("race a car") == false);
  assert(isPalindrome("Was it a car or a cat I saw?") == true);
  assert(isPalindrome("No 'x' in Nixon") == true);
  assert(isPalindrome("12321") == true);
  assert(isPalindrome("12345") == false);

  cout << "All tests passed!" << endl;

  return 0;
}
