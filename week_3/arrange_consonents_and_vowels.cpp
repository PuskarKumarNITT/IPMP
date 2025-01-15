// https://www.geeksforgeeks.org/problems/arrange-consonants-and-vowels/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printlist(Node *head) {
    if (head == NULL)
        return;
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void append(struct Node **headRef, char data) {
    struct Node *new_node = new Node(data);
    struct Node *last = *headRef;

    if (*headRef == NULL) {
        *headRef = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}


// } Driver Code Ends
/*
Structure of the node of the linked list is as
struct Node
{
    char data;
    struct Node *next;

    Node(char x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    bool isVowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c =='o' || c == 'u';
    }
    // Function to rearrange the linked list based on vowels
    struct Node *arrangeCV(Node *head) {
        // code here
        if(!head || !head->next) return head;
        Node *head_c = NULL,*head_v = NULL,*temp_c = NULL,*temp_v = NULL;
        Node *temp = head;
        while(temp){
            if(isVowel(temp->data)){
                if(!head_v){
                    head_v = temp;
                    temp_v = head_v;
                }else{
                    temp_v->next = temp;
                    temp_v = temp_v->next;
                }
            }else{
                if(!head_c){
                    head_c = temp;
                    temp_c = head_c;
                }else{
                    temp_c->next = temp;
                    temp_c = temp_c->next;
                }
            }
            temp = temp->next;
        }
        if(temp_c) temp_c->next = NULL;
        if(!head_v) return head_c;
        else if(!head_c) return head_v;
        temp_v->next = head_c;
        return head_v;
    }
};


//{ Driver Code Starts.

// task is to complete this function
int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        vector<char> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        char number;
        while (ss >> number) {
            arr.push_back(number);
        }
        if (arr.empty()) {
            return NULL;
        }
        char val = arr[0];
        int size = arr.size();

        Node *head = new Node(val);
        Node *tail = head;

        for (int i = 1; i < size; i++) {
            val = arr[i];
            tail->next = new Node(val);
            tail = tail->next;
        }

        Solution obj;
        head = obj.arrangeCV(head);
        printlist(head);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends