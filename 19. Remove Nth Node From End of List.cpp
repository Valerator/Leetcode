// Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

// Example 1:
// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]


// Example 2:
// Input: head = [1], n = 1
// Output: []


// Example 3:

// Input: head = [1,2], n = 1
// Output: [1]



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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr) //если лист пустой, то возвращаем его же
            return nullptr;
        if(head->next == nullptr) //если в листе всего одно значение возвращаем nullptr
            return nullptr;
        int len = 0; //длина листа
        ListNode* temp = head;
        while(temp != nullptr) {//считаем длину листа
            len++;
            temp = temp->next; 
        }
        len -= n; //длина листа, до нашего элемента
        if(len == 0) { //если длина равна 0, то просто оставляем все как было, до первого элемента
            temp = head->next;
            head->next = nullptr;
            delete(head);
            return temp;            
        } 
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while(len > 0) { //перепичываем, пока не дошли до конца длины
            prev = curr;
            curr = curr->next;
            len--;
        }
        //оставляем хвост без найденного элемента
        prev->next = curr->next;
        curr->next = nullptr;
        delete(curr);
        return head;
    }
};
