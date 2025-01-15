// https://www.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element
  Return the node which points to the head of the new LinkedList
  Node is defined as
    struct node
    {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/

class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        // Complete this method
        if(!head || !head->next || k == 1) return head;
        int len = 0;
        Node *temp = head;
        while(temp){
            len ++;
            temp = temp->next;
        }
        int val = k;
        Node *head_ret = NULL;
        temp = NULL;
        Node *last = head;
        while(len > 0){
            Node *back= NULL,*follow = NULL,*first = (temp)? temp: head;
            val = k;
            while(val-- && first){
                back = follow ;
                follow = first;
                first = first->next;
                follow->next = back;
            }
            if(!head_ret) head_ret = follow;
            else{
                last->next = follow;
                last = temp;
            }
            temp = first;
            len -= k;
        }
        return head_ret;
    }
};


//{ Driver Code Starts.

/* Driver program to test above function*/
int main(void) {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        Node* head = new Node(data);
        Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.reverseKGroup(head, k);
        printList(head);
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends