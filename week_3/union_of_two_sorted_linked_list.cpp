// https://www.geeksforgeeks.org/problems/union-of-two-linked-list/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }

    int data = arr[0];
    Node* head = new Node(data);
    Node* tail = head;
    for (int i = 1; i < arr.size(); ++i) {
        data = arr[i];
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
/*
// structure of the node is as follows

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
    struct Node* makeUnion(struct Node* head1, struct Node* head2) {
        // code here
        set<int> s;
        Node *temp = head1;
        while(temp){
            s.insert(temp->data);
            temp = temp->next;
        }
        temp  = head2;
        while(temp){
            s.insert(temp->data);
            temp = temp->next;
        }
        Node *res = NULL;
        temp = NULL;
        for(auto pr : s){
            if(!res){
                res = new Node(pr);
                temp = res;
            }else{
                temp->next = new Node(pr);
                temp = temp->next;
            }
        }
        return res;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        Node* first = buildList();

        Node* second = buildList();
        Solution obj;
        Node* head = obj.makeUnion(first, second);
        printList(head);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends