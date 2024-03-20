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
    vector<int> result1 = productExceptSelf(nums1);
    cout << "Output for nums1: ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> nums2 = {-1, 1, 0, -3, 3};
    vector<int> result2 = productExceptSelf(nums2);
    cout << "Output for nums2: ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}