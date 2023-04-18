// Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

// An integer a is closer to x than an integer b if:

// |a - x| < |b - x|, or
// |a - x| == |b - x| and a < b
 

// Example 1:

// Input: arr = [1,2,3,4,5], k = 4, x = 3
// Output: [1,2,3,4]

// Example 2:

// Input: arr = [1,2,3,4,5], k = 4, x = -1
// Output: [1,2,3,4]


class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans(k);
        int i = Search_Binary(arr, x); //с помощью бинарного поиска ищем позицию на которой элемент
 
        int left = i - 1;
        int right = i;
 
        while (k-- > 0) { //двигаясь вправо и влево ищем интервал, на которм находятся значения
            if (left < 0 || (right < arr.size() && abs(arr[left] - x) > abs(arr[right] - x))) {
                right++;
            } else {
                left--;
            }
        }
 
        int n = 0;    
        left++;
        while (left < right) {
            ans[n] = arr[left];
            n++;
            left++;
        }
        return ans;
    }
    
    int Search_Binary(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
 
        while (left <= right) {
            int mid = left + (right - left) / 2;
 
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                return mid;   
            }
        }
        return left; 
    }   
};
