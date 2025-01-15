// https://leetcode.com/problems/swapping-nodes-in-a-linked-list/description/

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
    ListNode* swapNodes(ListNode* head, int k) {
        if(!head | !head->next) return head;
        ListNode *back = NULL;
        ListNode *slow = head,*fast = head;
        int val = k;
        while(val--){
            fast = fast->next;
        }
        while(fast){
            slow = slow->next;
            fast = fast->next;
        }
        back = slow;
        slow = head;
        val =  k;
        val--;
        while(val--) slow = slow->next;
        int temp = slow->val;
        slow->val = back->val;
        back->val = temp;
        return head;
    }
};