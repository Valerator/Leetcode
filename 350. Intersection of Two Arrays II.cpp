// Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

 

// Example 1:

// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2,2]
// Example 2:

// Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// Output: [4,9]
// Explanation: [9,4] is also accepted.

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> answer;
        sort(nums1.begin(), nums1.end()); //сортируем вектора в порядке возрастания
        sort(nums2.begin(), nums2.end());
        int i = 0;
        int j = 0;
        while(i < nums1.size() && j < nums2.size()) {
            if(nums1[i] == nums2[j]) {
                answer.push_back(nums1[i]); //если элементы совпадают, записываем их в ответ
                i++;
                j++;
            } else if(nums1[i] > nums2[j]) { //если в первом массиве число больше, то двинаем второй массив на один
                j++;
            } else { //а тут уже наоборот
                i++;
            }
        }
        return answer;
    }
};
