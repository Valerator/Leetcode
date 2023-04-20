
// Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

// Example 1:

// Input: s = "Let's take LeetCode contest"
// Output: "s'teL ekat edoCteeL tsetnoc"
  
// Example 2:

// Input: s = "God Ding"
// Output: "doG gniD"


class Solution {
public:
    string reverseWords(string s) {
        string ans;
        for(int i = 0; i < s.length(); ++i) {
            int j = i;
            while(j < s.length() && s[j] != ' ') //ищем слово до пробела
                ++j;
            if(i == 0)
                ans += reverseWord(s.substr(i, j - i));
            else
                ans += " " + reverseWord(s.substr(i, j - i));
            i = j;
        }
        return ans;
    }

    string reverseWord(string s) {
        for(int i = 0; i < s.size() / 2; ++i) {
            swap(s[i], s[s.size() - i - 1]);
        }
        return s;
    }
};
