/*
if a number in input has a left neighbour (n-1) then it cant be start of a seq.

once you get a number thats start of a seq then check length of this seq by
checking if there is another number that comes after it. n+1
*/

#include <cassert>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int longestConsecutive(vector<int> &nums) {
  unordered_set<int> s(nums.begin(), nums.end());
  int longest = 0;

  for (auto n : s) {
    // check for left neighbour
    if (!s.count(n - 1)) {
      // start of seq. count length of this seq
      int length = 1;
      // check if the next num in seq exists in input array
      while (s.count(length + n)) {
        length++;
      }
      longest = max(length, longest);
    }
  }
  return longest;
}

int main() {

  vector<int> nums = {100, 4, 200, 1, 3, 2};
  int expected = 4;
  int result = longestConsecutive(nums);
  assert(result == expected);

  // Test Case 3: Empty sequence
  vector<int> nums3;
  int expected3 = 0;
  int result3 = longestConsecutive(nums3);
  assert(result3 == expected3);

  // Test Case 4: Sequence with negative numbers
  vector<int> nums4 = {-2, -1, 0, 1, 2, 3, 4};
  int expected4 = 7;
  int result4 = longestConsecutive(nums4);
  assert(result4 == expected4);

  // Test Case 5: Sequence with duplicates
  vector<int> nums5 = {1, 2, 2, 3, 4, 4, 5, 6};
  int expected5 = 6;
  int result5 = longestConsecutive(nums5);

  std::cout << "All test cases passed successfully!" << std::endl;

  return 0;
}