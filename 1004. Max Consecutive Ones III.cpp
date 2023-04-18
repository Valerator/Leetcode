// Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

 

// Example 1:

// Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
// Output: 6
// Explanation: [1,1,1,0,0,1,1,1,1,1,1]
// Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
  
// Example 2:

// Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
// Output: 10
// Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
// Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.


class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        return find_len(nums, k, 1);
    }

    unsigned find_len(vector<int> &s, unsigned k, unsigned c) {
        unsigned maxlen = 0;
        unsigned cnt = 0;
        unsigned l = 0, r = 0;
      
        while (r < s.size()) {
            
            if (s[r] != c)
                ++cnt;
  
            while (cnt > k) {
                if (s[l] != c)
                    --cnt;
                ++l;
            }
            maxlen = max(maxlen, r - l + 1);
            ++r;
        }
        return maxlen;
    }

};
