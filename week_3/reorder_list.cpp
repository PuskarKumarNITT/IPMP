// https://leetcode.com/problems/reorder-list/description/

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
 void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        // finding mid element
        ListNode *slow = head,*fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *mid = slow;
        ListNode *second = slow->next;
        mid->next = nullptr;
        // push into stack
        stack<ListNode *> stk;
        while(second){
            stk.push(second);
            second = second->next;
        }
        // reversing in pair
        ListNode *first = head;
        while(!stk.empty()){
            ListNode *stkele = stk.top();
            stk.pop();
            ListNode *temp = first->next;
            first->next = stkele;
            stkele->next = temp;
            first = temp;
        }
        if(first) first->next = NULL;
    }
};