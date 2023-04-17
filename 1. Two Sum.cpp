// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.

 

// Example 1:

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
// Example 2:

// Input: nums = [3,2,4], target = 6
// Output: [1,2]
// Example 3:

// Input: nums = [3,3], target = 6
// Output: [0,1]

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       vector<int> ans(2); //вектор из двух значений для ответа
       map<int, int> m; //словарь для значений и позиций
       for(size_t i = 0; i < nums.size(); ++i) {
           int value = target - nums[i]; 
           if(m.find(value) != m.end()) { //ищем если такой вычет имеется в словаре
               ans[0] = i; //то записываем ответ
               ans[1] = m.find(value)->second;
               break; //выходим из цикла
           }
           m[nums[i]] = i; //записываем в словарь значение и позицию
       }
       return ans;
    }
};
