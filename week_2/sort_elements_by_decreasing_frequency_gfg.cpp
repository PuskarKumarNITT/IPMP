// https://www.geeksforgeeks.org/problems/sorting-elements-of-an-array-by-frequency-1587115621/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
        
  public:
//   bool comp(pair<int,int> p1,pair<int,int> p2){
//             if(p1.first == p2.first) return p1.second > p2.second;
//             return p1.first > p2.first;
//         }
    // Complete this function
    // Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(vector<int>& arr) {
        vector<int> ans;
        unordered_map<int,int> m;
        for(int i: arr) m[i]++;
        vector<pair<int,int>> v;
        for(auto pr: m){
            v.push_back({pr.second,pr.first});
        }
        sort(v.begin(),v.end(),
        [](pair<int,int> p1,pair<int,int> p2){
            if(p1.first == p2.first) return p1.second < p2.second;
            return p1.first > p2.first;
        });
        for(auto pr: v){
            int val = pr.second;
            int len = pr.first;
            while(len--){
                ans.push_back(val);
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

        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(arr);
        for (int i : v)
            cout << i << " ";
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends