// https://www.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
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

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
// User function template for C++

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
    Node* divide(Node* head) {
        // code here
        if(!head || !head->next) return head;
        Node *head_o = NULL,*head_e = NULL,*temp_o = NULL,*temp_e = NULL,*temp = head;
        while(temp){
            if(temp->data & 1){
                if(!head_o){
                    head_o = temp;
                    temp_o = head_o;
                }else{
                    temp_o->next = temp;
                    temp_o = temp_o->next;
                }
            }else{
                if(!head_e){
                    head_e = temp;
                    temp_e = head_e;
                }else{
                    temp_e->next = temp;
                    temp_e = temp_e->next;
                }
            }
            temp = temp->next;
        }
        if(temp_o) temp_o->next = NULL;
        if(!head_e) return head_o;
        else if(!head_o) return head_e;
        temp_e->next = head_o;
        return head_e;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty())
            continue;

        int data = arr[0];
        int N = arr.size();
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 1; i < N; ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        Node *ans = ob.divide(head);
        printList(ans);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends