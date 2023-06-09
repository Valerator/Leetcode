// You are given two lists of closed intervals, firstList and secondList, where firstList[i] = [starti, endi] and secondList[j] = [startj, endj]. Each list of intervals is pairwise disjoint and in sorted order.

// Return the intersection of these two interval lists.

// A closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.

// The intersection of two closed intervals is a set of real numbers that are either empty or represented as a closed interval. For example, the intersection of [1, 3] and [2, 4] is [2, 3].

 

// Example 1:

// Input: firstList = [[0,2],[5,10],[13,23],[24,25]], secondList = [[1,5],[8,12],[15,24],[25,26]]
// Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]

// Example 2:

// Input: firstList = [[1,3],[5,9]], secondList = []
// Output: []


class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstlist, vector<vector<int>>& secondlist) {
        if(firstlist.empty() || secondlist.empty()) {
            return {}; //если какой-то из векторов пуст, то возвращаем пустоту
        }
        vector<vector<int>> ans;
        size_t i = 0, j = 0;
        while(i < firstlist.size() && j < secondlist.size()) {
            if(firstlist[i][0] < secondlist[j][0] && firstlist[i][1] < secondlist[j][0]) { //если первый элемент находится между двумя вторыми 
                i++;
            } else if(secondlist[j][0] < firstlist[i][0] && secondlist[j][1] < firstlist[i][0]) { //если наоборот
                j++;
            } else {
                vector<int> temp(2);
                if(firstlist[i][0] >= secondlist[j][0]) {
                    temp[0] = firstlist[i][0];
                } else {
                    temp[0] = secondlist[j][0]; 
                }
                if(firstlist[i][1] <= secondlist[j][1]) {
                    temp[1] = firstlist[i][1];
                    i++;
                } else {
                    temp[1] = secondlist[j][1];
                    j++;
                }
                ans.push_back(temp);
            }
        }
        return ans;
    }
};
