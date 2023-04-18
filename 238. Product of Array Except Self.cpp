// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

// You must write an algorithm that runs in O(n) time and without using the division operation.


// Example 1:

// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]

// Example 2:

// Input: nums = [-1,1,0,-3,3]
// Output: [0,0,9,0,0]


//считаем префиксы и постфиксы

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size(), 1);
        vector<int> suffix(nums.size(), 1);
        vector<int> ans(nums.size());
        for (int i = 1; i < nums.size(); i++)
            prefix[i] = nums[i - 1] * prefix[i - 1];
        for (int j = nums.size() - 2; j >= 0; j--)
            suffix[j] = nums[j + 1] * suffix[j + 1];
        for (int i = 0; i < nums.size(); i++)
            ans[i] = prefix[i] * suffix[i];
        return ans;
    }
};
