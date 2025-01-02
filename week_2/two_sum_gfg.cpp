// https://www.geeksforgeeks.org/problems/key-pair5616/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        int i=0 ,j =arr.size()-1,n = arr.size();
        while(i<j){
            if(arr[i]+arr[j] > target) j--;
            else if(arr[i]+arr[j] < target) i++;
            else return true;
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int x;
        cin >> x;
        cin.ignore();

        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        auto ans = ob.twoSum(arr, x);
        cout << (ans ? "true" : "false") << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends