#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> mp;
    int n = nums.size();
    for(int i = 0; i < n; ++i) {
        auto diff = target - nums[i];
        if(mp.find(diff) != mp.end()) {
            return {mp[diff], i};
        }
        mp.insert({nums[i], i});
    }
    return {};
}

int main() {
    
    std::vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    assert((twoSum(nums1, target1) == std::vector<int>{0, 1}));

    std::vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    assert((twoSum(nums2, target2) == std::vector<int>{1, 2}));

    std::vector<int> nums3 = {3, 3};
    int target3 = 6;
    assert((twoSum(nums3, target3) == std::vector<int>{0, 1}));

    std::cout << "All test cases passed successfully!" << std::endl;

    return 0;
}
