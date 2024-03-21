/*


*/

#include <bits/stdc++.h>
#include <cassert>


using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, 1);
    
    int prefix = 1;

    for (int i = 0; i < n; i++) {
        result[i] = prefix;
        prefix = prefix * nums[i];
    }

    int postfix = 1;

    for (int i = n - 1; i >= 0; i--) {
        result[i] = result[i] * postfix;
        postfix = postfix * nums[i];
    }
    
    return result;
}


int main() {

    vector<int> nums1 = {1, 2, 3, 4};
    assert((productExceptSelf(nums1) == std::vector<int>{24,12,8,6}));

    vector<int> nums2 = {-1, 1, 0, -3, 3};
    assert((productExceptSelf(nums2) == std::vector<int>{0,0,9,0,0}));

    std::cout << "All test cases passed successfully!" << std::endl;

    return 0;
}