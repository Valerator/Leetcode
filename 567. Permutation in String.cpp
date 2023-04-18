// Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

// In other words, return true if one of s1's permutations is the substring of s2.

 

// Example 1:

// Input: s1 = "ab", s2 = "eidbaooo"
// Output: true
// Explanation: s2 contains one permutation of s1 ("ba").
  
// Example 2:

// Input: s1 = "ab", s2 = "eidboaoo"
// Output: false


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) //если подстрока больше строки, то выводим false
            return false;
        vector<int> temp_1(26), temp_2(26); //два вектора на количества латинских букв
        for(char c: s1)
            temp_1[c - 'a'] ++; //количество букв в строке 1
        int k =  s1.size();
        for(int i = 0; i < s1.size() - 1; i++) 
            temp_2[s2[i] - 'a'] ++; //количество букв в строке 2

        for(int i = k - 1; i < s2.size(); i ++){
            temp_2[s2[i] - 'a'] ++;
            if(temp_1 == temp_2) 
                return true;
            temp_2[s2[i - (k - 1)] - 'a'] --;
        }
        return false;
    }
};
