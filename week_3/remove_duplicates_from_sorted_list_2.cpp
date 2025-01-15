//https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/

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
        map<int,int> m;
        ListNode *temp = head;
        while(temp){
            m[temp->val]++;
            temp =temp->next;
        }
        ListNode *head1 = NULL,*temp1 = NULL;
        for(auto pr: m){
            if(pr.second == 1){
                if(!head1){
                    head1 = new ListNode (pr.first);
                    temp1 = head1;
                }else{
                    temp1->next = new ListNode(pr.first);
                    temp1 = temp1->next;
                }
            }
        }
        return head1;
    }
};