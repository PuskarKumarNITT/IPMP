// https://www.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Complete this function
    // Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(vector<int>& arr) {
        if(arr.size() < 1) return false;
        int sum = arr[0];
        unordered_map<int,int> m;
        m[sum]++;
        for(int i=1;i<arr.size();++i){
            sum += arr[i];
            m[sum]++;
        }
        if(m.find(0) != m.end()) return true;
        for(auto pr: m){
            if(pr.second > 1) return true;
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
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution obj;
        if (obj.subArrayExists(arr))
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends