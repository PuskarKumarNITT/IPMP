//https://www.geeksforgeeks.org/problems/print-diagonally4331/1

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	public:
	vector<int> downwardDiagonal(int N, vector<vector<int>> A)
	{
	    int n = N;
		vector<int> ans;
		for(int i=0;i<n;++i){
		    int row = 0,coln = i;
		    while(row < N && coln >= 0  ){
		        ans.push_back(A[row][coln]);
		        row++;
		        coln--;
		    }
		}
		for(int i=1;i<n;++i){
		    int row = i,coln = n-1;
		    while(row <n && coln >=0){
		        ans.push_back(A[row][coln]);
		        row++;
		        coln--;
		    }
		}
		return ans;
	}

};

//{ Driver Code Starts.



int main()
{

    
    int t;
    cin >> t;
    while(t--) 
    {
        int n;
        cin >> n;

        vector<vector<int>> A(n, vector<int>(n));

        for(int i = 0; i < n; i++)
        	for(int j = 0; j < n; j++)
        		cin >> A[i][j];

        Solution obj;
        vector<int> ans = obj.downwardDiagonal(n, A);

        for(auto i:ans)
        	cout << i << " ";

	    cout << "\n";
    
cout << "~" << "\n";
}

    return 0;
}

// } Driver Code Ends