// Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

// Letters are case sensitive, for example, "Aa" is not considered a palindrome here.

 

// Example 1:

// Input: s = "abccccdd"
// Output: 7
// Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
  
// Example 2:

// Input: s = "a"
// Output: 1
// Explanation: The longest palindrome that can be built is "a", whose length is 1.

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp; //словарь для символа и количество их в строке
        for(int i = 0; i < s.size(); i++) {
            ++mp[s[i]];
        }
        int res = 0;
        int odd = 0;
        for(auto k: mp) {
            if(k.second % 2 == 0) //если количество элементов четно, то они все могут быть в полиндроме
                res += k.second;
            else if(k.second % 2 != 0 && odd == 0) { //если нечетное количество элементов в первый раз, то они все будут в палиндроме
                odd = 1;
                res += k.second;
            } else if (k.second % 2 != 0 && odd != 0) { //если больше чем один, то уже на один элемент меньше
                res = res + k.second - 1;
            }
        }
        return res;
    }
};
