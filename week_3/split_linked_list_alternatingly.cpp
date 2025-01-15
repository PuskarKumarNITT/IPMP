// https://www.geeksforgeeks.org/problems/split-singly-linked-list-alternatingly/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    // Function to split a linked list into two lists alternately
    vector<Node*> alternatingSplitList(struct Node* head) {
        // Your code here
        if(!head) return {NULL,NULL};
        if(!head->next) return {head,NULL};
        Node *head1 = NULL,*head2 = NULL,*temp1 = NULL,*temp2 = NULL,*temp = head;
        int count = 0;
        while(temp){
            if(count &1){
                if(!head2){
                    head2 = temp;
                    temp2 = head2;
                }else{
                    temp2->next = temp;
                    temp2 = temp2->next;
                }
            }else{
                if(!head1){
                    head1 = temp;
                    temp1 = head1;
                }else{
                    temp1->next = temp;
                    temp1 = temp1->next;
                }
            }
            count++;
            temp = temp->next;
        }
        if(temp1) temp1->next = NULL;
        if(temp2) temp2->next = NULL;
        return {head1,head2};
    }
};


//{ Driver Code Starts.

void printList(struct Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
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

        struct Node* head = new Node(arr[0]);
        struct Node* tail = head;

        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }

        Solution ob;
        vector<Node*> result = ob.alternatingSplitList(head);
        printList(result[0]);
        printList(result[1]);
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends