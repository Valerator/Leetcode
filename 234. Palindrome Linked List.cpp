// Given the head of a singly linked list, return true if it is a 
// palindrome
//  or false otherwise.

 

// Example 1:


// Input: head = [1,2,2,1]
// Output: true
// Example 2:


// Input: head = [1,2]
// Output: false

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* l;
        l = head;
        stack<int> s_1; //создаем стэк в котором будет хранится значения из первой половины листа
        while(head != nullptr) { //заполняем стэк
            s_1.push(head->val);
            head = head->next;
        }
        while(l != nullptr) { //работаем со второй половиной листа
            if(l->val != s_1.top()) //если что-то не совпадает то сразу же выводим false
                return false;
            s_1.pop();
            l = l->next;
        }
        return true; //если прошли весь цикл, то true 
    }
};
