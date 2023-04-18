// You are given the heads of two sorted linked lists list1 and list2.

// Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

// Return the head of the merged linked list.

// Example 1:
// Input: list1 = [1,2,4], list2 = [1,3,4]
// Output: [1,1,2,3,4,4]


// Example 2:
// Input: list1 = [], list2 = []
// Output: []


// Example 3:
// Input: list1 = [], list2 = [0]
// Output: [0]

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //если какой-то из листов равен nullptr, то возвращаем другой лист
        if(list1 == nullptr)
            return list2;
        if(list2 == nullptr)
            return list1;
        ListNode *head = nullptr;
        ListNode *temp = nullptr;
        while(list1 != nullptr && list2 != nullptr) {
            if(head == nullptr) {
                if(list1->val <= list2->val) { //сравниваем значения в узлах и решаем какой следующий элемент вставить в лист ответа
                    head = temp = list1;
                    list1 = list1->next;
                } else {
                    head = temp = list2;
                    list2 = list2->next;
                }
            } else {
                if(list1->val <= list2->val) {
                    temp->next = list1;
                    temp = list1;
                    list1 = list1->next;
                } else {
                    temp->next = list2;
                    temp = list2;
                    list2 = list2->next;
                }
            }
        }
        if(list1 != nullptr)
            temp->next = list1;
        if(list2 != nullptr)
            temp->next = list2;
        return head;
    }
};
