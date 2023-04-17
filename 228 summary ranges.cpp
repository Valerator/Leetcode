class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int i = 0;
        while(i < nums.size()) {
            int start = nums[i];
            int end;
            while(1 + i < nums.size() && nums[i + 1] == nums[i] + 1) { //смотрим сколько чисел подряд удволетворяют условию
                i++;
            }
            end = nums[i];
            if(start == end) { //если не образуется последовательность
                result.push_back(to_string(start)); //to_string делает из чего-либо строку
            } else { //если последовательность все-таки есть
                result.push_back(to_string(start) + "->" + to_string(end)); 
            }
            i++;
        }
        return result;
    }
};
