// https://www.geeksforgeeks.org/problems/boolean-matrix-problem-1587115620/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to modify the matrix such that if a matrix cell matrix[i][j]
    // is 1 then all the cells in its ith row and jth column will become 1.
    void booleanMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m= mat[0].size();
        unordered_set<int> row,coln;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(mat[i][j]){
                    row.insert(i);
                    coln.insert(j);
                }
            }
        }
        // row update
        for(int x: row){
            for(int i=0;i<m;++i){
                if(!mat[x][i]) mat[x][i] =1;
            }
        }
        // coln update
        for(int x: coln){
            for(int i=0;i<n;++i){
                if(!mat[i][x]) mat[i][x] =1;
            }
        }
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int row, col;
        cin >> row >> col;
        vector<vector<int> > matrix(row);
        for (int i = 0; i < row; i++) {
            matrix[i].assign(col, 0);
            for (int j = 0; j < col; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        ob.booleanMatrix(matrix);

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends