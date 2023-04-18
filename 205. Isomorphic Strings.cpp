// Given two strings s and t, determine if they are isomorphic.

// Two strings s and t are isomorphic if the characters in s can be replaced to get t.

// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

 

// Example 1:

// Input: s = "egg", t = "add"
// Output: true
  
// Example 2:

// Input: s = "foo", t = "bar"
// Output: false
  
// Example 3:

// Input: s = "paper", t = "title"
// Output: true


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map <char, int> mp_1; //создаем словарь для элемента и его количество в слове
        unordered_map <char, int> mp_2;
        vector <int> vec_1;
        vector <int> vec_2;
        int sum_1 = 0, sum_2 = 0;
        for(auto s_el: s) {
            if(mp_1.count (s_el) == 0) {
            mp_1[s_el] = sum_1;
            ++sum_1;
            }
            vec_1.push_back(mp_1[s_el]);//записываем в вектор количество элементов
        }
        for(auto t_el: t) {
            if(mp_2.count(t_el) == 0) {
            mp_2[t_el] = sum_2;
            ++sum_2;
            }
            vec_2.push_back(mp_2[t_el]);
        }
        return vec_1 == vec_2; //сравниваем два вектора
    }
};
