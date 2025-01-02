// https://www.geeksforgeeks.org/problems/product-array-puzzle4525/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        vector<int> ans(arr.size());
        long long res = 1;
        int zero = 0;
        for(int i: arr){
            if(i == 0) zero++;
            else res *= i;
        }
        int len = arr.size();
        for(int i=0;i<len;++i){
            if(arr[i] == 0){
                if(zero > 1) ans[i] = 0;
                else ans[i] = res;
            }else {
                if(zero) ans[i] = 0;
                else ans[i] = res/arr[i];
            }
        }
        return ans;
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
        vector<int> res = obj.productExceptSelf(arr);

        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends