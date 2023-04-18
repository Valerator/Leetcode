// Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

 

// Example 1:

// Input: nums = [1,2,3,1], k = 3
// Output: true
  
// Example 2:

// Input: nums = [1,0,1,1], k = 1
// Output: true
  
// Example 3:

// Input: nums = [1,2,3,1,2,3], k = 2
// Output: false

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
         for(int i = 0; i < nums.size() - 1; i++){
            int finish = min((int)nums.size(), i + k + 1);
            if(find(nums.begin() + i + 1, nums.begin() + finish, nums[i]) != nums.begin() + finish) {
                return true;
            }
        }
        return false;
    }
};
