//https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *slow = head,*fast = head->next;
        while(fast){
            if(slow->val == fast->val){
                ListNode *temp = fast;
                fast = fast->next;
                delete temp;
                slow->next = fast;
            }else{
                slow = slow->next;
                fast = fast->next;
            }
        }
        return head;
    }
};