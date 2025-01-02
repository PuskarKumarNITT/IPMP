// https://www.geeksforgeeks.org/problems/two-numbers-with-sum-closest-to-zero1737/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        int closestToZero(int arr[], int n)
        {
            sort(arr,arr+n);
            int i = 0,j= n-1;
            int ans =arr[0]+arr[j];
            while(i<j){
                int num = arr[i]+arr[j];
                if(abs(num) < abs(ans)) ans = num;
                if(abs(num) == abs(ans)) ans = max(ans,num);
                if(num == 0) return num;
                if(num < 0) i++;
                else j--;
            }
            return ans;
        }
};

//{ Driver Code Starts.
int main ()
{
    int t; 
    cin >> t;
    while (t--)
    {
        int n; 
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.closestToZero(arr, n) << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends