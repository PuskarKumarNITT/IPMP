// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int minP = INT_MAX;
       int maxP = 0;
       for(int i=0;i<prices.size();++i){
            minP = min(minP,prices[i]);
            maxP = max(maxP,prices[i]-minP);
       }
       return maxP;
    }
};
//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        //cout << ob.equilibriumPoint(arr) << endl;
        cout << "~" << endl;
    }
}