// https://www.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

//{ Driver Code Starts
#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <ios>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution {
  public:
   struct Node* reverseLinkedList(struct Node* root){
        struct Node *back = NULL,*follow = NULL,*first = root;
        while(first){
            follow = first;
            first = first->next;
            follow->next = back;
            back = follow;
        }
        return follow;
    }
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head) {
        if(!head || !head->next) return true;
        if(!head->next->next && head->data == head->next->data) return true;
        int len = 0;
        Node *slow = head,*fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        struct Node *rev = reverseLinkedList(slow);
        struct Node *temp1 = head,*temp2 = rev;
        while(temp1 && temp2){
            if(temp1->data != temp2->data) return false;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        reverseLinkedList(rev);
        return true;
    }
};


//{ Driver Code Starts.

/* Function to print nodes in a given linked list */
void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
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

        if (arr.empty()) {
            cout << "empty" << endl;
            continue;
        }

        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        Solution ob;
        if (ob.isPalindrome(head))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        // Clean up the remaining nodes to avoid memory leaks
        while (head != NULL) {
            struct Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
    return 0;
}

// } Driver Code Ends