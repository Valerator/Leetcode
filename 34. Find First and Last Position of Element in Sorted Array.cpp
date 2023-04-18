// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

// If target is not found in the array, return [-1, -1].

// You must write an algorithm with O(log n) runtime complexity.

 

// Example 1:

// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]

// Example 2:

// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]

// Example 3:

// Input: nums = [], target = 0
// Output: [-1,-1]

//Массив у нас отсортирован, значит используем бинарный поиск, справа для последнего вхождения
//и слева для первого вхождения

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2);
        ans[0] = -1;
        ans[1] = -1;
        if(nums.size() == 0) {
            return ans;
        } else {
            ans[0] = Search_Binary_left(nums, target);
            if(ans[0] == -1) {//если у нас не нашелся элемент бинарным посиком слева, то и справа не найдется
                ans[1] = -1;
            } else 
                ans[1] = Search_Binary_right(nums, target, ans[0]);
            return ans;
        }
    }

    int Search_Binary_left(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int result = -1;
        while (left <= right) {
        
            int mid = (left + right) / 2;

            if (target == nums[mid]) {
                result = mid;
                right = mid - 1;
            }
 
            else if (target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return result;
    }

    int Search_Binary_right(vector<int>& nums, int target, int left) {                    
        int right = nums.size() - 1;
        int result = -1;
 
        while (left <= right) {
            int mid = (left + right) / 2;
        
            if (target == nums[mid]) {
                result = mid;
                left = mid + 1;
            }
 
            else if (target < nums[mid]) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return result;
    }
};
