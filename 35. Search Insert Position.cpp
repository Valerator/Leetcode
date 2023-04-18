// Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

// You must write an algorithm with O(log n) runtime complexity.

 

// Example 1:

// Input: nums = [1,3,5,6], target = 5
// Output: 2
  
// Example 2:

// Input: nums = [1,3,5,6], target = 2
// Output: 1
  
// Example 3:

// Input: nums = [1,3,5,6], target = 7
// Output: 4

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(target < nums[0]) {
            return 0; //если данное значение меньше первого значения, то надо вставить его вначало
        }
        if(target > nums[nums.size() - 1]) {
            return nums.size();//если данное значение больше последнего, то надо вставить его вконец
        }
        //далее бинарный поиск
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right) {
            int mid = (left + right) / 2;
            if(nums[mid] == target) {
                return mid;
            } else if (target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
