// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

// A subarray is a contiguous non-empty sequence of elements within an array.

 

// Example 1:

// Input: nums = [1,1,1], k = 2
// Output: 2
  
// Example 2:

// Input: nums = [1,2,3], k = 3
// Output: 2


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0, sum = 0;
        map<int, int> m;
        m[0]++;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            count += m[sum - k];
            m[sum]++;
        }
        
        return count;
    }
};
