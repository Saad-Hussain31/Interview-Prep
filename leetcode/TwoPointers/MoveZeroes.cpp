/* Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

 Note that you must do this in-place without making a copy of the array.

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

Example 2:

Input: nums = [0]
Output: [0]

Constraints:

    1 <= nums.length <= 104
    -231 <= nums[i] <= 231 - 1

 
Follow up: Could you minimize the total number of operations done? 
*/

#include <string>
#include <iostream>
#include <vector>

class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        int n = nums.size();
        int left{0};


        for(int i=0; i<n; ++i)
        {
            if(nums[i] != 0) {
                nums[left++] = nums[i];
            }
        }
        while (left < n) {
            nums[left++] =0;
        }
    }
};

void assertEqual(std::vector<int> rhs, std::vector<int> lhs, std::string identifier)
{
    if(rhs != lhs) {
        std::cerr << identifier << ": Not equal" << std::endl;
        return;
    }
    std::cout << identifier << ": Is equal" << std::endl;
}

int main(void) {
    auto sln = Solution{};

    auto testData1 = std::vector<int>{1,0,2,3,4,0,6};
    sln.moveZeroes(testData1);
    assertEqual(testData1, {1,2,3,4,6,0,0}, "Test1");

    auto testData2 = std::vector<int>{12,4,7,0,6,1,4,0,0,3,0};
    sln.moveZeroes(testData2);
    assertEqual(testData2, {12,4,7,6,1,4    ,3,0,0,0,0}, "Test2");
    
    auto testData3 = std::vector<int>{0};
    sln.moveZeroes(testData3);
    assertEqual(testData3, {0}, "Test3");
    return 0;
}