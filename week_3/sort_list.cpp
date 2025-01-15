//https://leetcode.com/problems/sort-list/

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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        vector<pair<ListNode *,int>> v;
        ListNode *temp = head;
        while(temp){
            v.push_back({temp,temp->val});
            temp = temp->next;
        }        
        sort(v.begin(),v.end(),[](pair<ListNode *,int> p1,pair<ListNode*,int>p2){return p1.second < p2.second;});
        head = v[0].first;
        temp = head;
        for(int i=1;i<v.size();++i){
            temp->next = v[i].first;
            temp = temp->next;
        }
        temp->next = NULL;
        return head;
    }
};