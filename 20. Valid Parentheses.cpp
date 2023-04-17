// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.
 

// Example 1:

// Input: s = "()"
// Output: true
// Example 2:

// Input: s = "()[]{}"
// Output: true
// Example 3:

// Input: s = "(]"
// Output: false

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(size_t i = 0; i < s.size(); i++) {
        if(st.empty() && (s[i] == '(' || s[i] == '{' || s[i] == '[')) {//если строка начинается с открвающейся скобкой
            st.push(s[i]);
        } else if(st.empty() && (s[i] == ')' || s[i] == '}' || s[i] == ']')) {//если строка пуста и она начинается с закрытой
            return false;
        } else if(s[i] == '(' || s[i] == '[' || s[i] == '{') { 
            st.push(s[i]);
        } else if(s[i] == ')' && st.top() == '(') { //смотрим совпадение скобок
            st.pop();
        } else if(s[i] == '}' && st.top() == '{') {
            st.pop();
        } else if(s[i] == ']' && st.top() == '[') {
            st.pop();
        } else {
            return false;
        }
    }
    return st.empty();
    }
};
