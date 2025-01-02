// https://www.geeksforgeeks.org/problems/row-with-minimum-number-of-1s5430/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minRow(vector<vector<int>> &mat) {
        int n = mat.size(),m = mat[0].size();
        pair<int,int> p;
        int f_r_zero = 0;
        for(int i=0;i<m;++i){
            if(mat[0][i] == 0) f_r_zero++;
        }
        p = {1,f_r_zero};
        for(int i=0;i<n;++i){
            int num = 0;
            for(int j=0;j<m;++j){
                if(mat[i][j] == 0) num++;
            }
            if(num > p.second) p = {i+1,num};
        }
        return p.first;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> mat(N, vector<int>(M));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        cout << ob.minRow(mat) << "\n";
        cout << "~\n";
    }
}
// } Driver Code Ends