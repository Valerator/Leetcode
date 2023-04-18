// Given a string s, return the longest 
// palindromic
 
// substring
//  in s.

 

// Example 1:

// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.
// Example 2:

// Input: s = "cbbd"
// Output: "bb"

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()) //если строка пустая - то возвращаем пустую строку
            return "";
        int N = s.size();
        int max_len = 1, start = 0; 
        for(int i = 0; i < N; ++i) {    
            int j = i, k = i;
            while(j >= 0 && k < N) {
                if(s[j] != s[k]) 
                    break;
                if(max_len < k - j + 1) {
                    max_len = k - j + 1; 
                    start = j;
                }
                j--;
                k++;
            }
            j = i; k = i + 1;
            while(j >= 0 && k < N) {
                if(s[j] != s[k]) 
                    break;
                if(max_len < k - j + 1) {
                    max_len = k - j + 1;
                    start = j;
                }
                j--;
                k++;
            }
        }
        return s.substr(start, max_len);
    }
};

//тыкаем в букву и от нее идем вправо и влево, проверяем полиндром ли это, если да, то какий длины
