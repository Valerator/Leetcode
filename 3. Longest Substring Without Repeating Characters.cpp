// Given a string s, find the length of the longest 
// substring
//  without repeating characters.

 

// Example 1:

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.
// Example 2:

// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
// Example 3:

// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() < 2) {
            return s.size(); //если длина меньше 2-ух символов, то выводим длину
        }
        int sum = 1; //одна буква найдется всегда, поэтому считаем с одного
        set<char> letters; //создаем set для хранения букв в подпоследовательности
        letters.insert(s[0]); //добавляем первый элемент
        size_t i = 1;
        int temp = 1;//текущая длина подстроки
        while(i < s.size()) {
            if(letters.find(s[i]) == letters.end()) { //если мы не находим такого элемента во множестве, то добавляем его и увеличиваем счетчик
                letters.insert(s[i]);
                i++;
                temp++;
                if(sum < temp) {
                    sum = temp; //меняем сумму если она уже не актуальна
                }
            } else {
                if(temp == 1) {
                    i++; //если текущая длина равна 1, то просто переходим к следующему элементу
                } else {
                    letters.clear(); //очищаем множество
                    i = i - temp + 1; //возвращаемся к элементу, который был вторым во множестве
                    temp = 0; //обнуляем счетчик
                }
            }
        }
        return max(temp, sum);//возвращаем максимальное значение
    }
};
