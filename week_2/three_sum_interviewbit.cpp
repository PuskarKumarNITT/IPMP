//https://www.interviewbit.com/problems/3-sum/
#include <bits/stdc++.h>
using namespace std;
class Solution{
    public: 
     int threeSumClosest(vector<int> &A,int B);
};
int Solution::threeSumClosest(vector<int> &A, int B) {
    sort(A.begin(),A.end());
    int n1 = A.size();
    if(n1 <3) return 0;
    int ans = A[0]+A[1]+A[2];
    int j,k;
    for(int i=0;i<n1-2;++i){
        j = i+1;
        k = n1-1;
        while(j<k){
            int num = A[i]+A[j]+A[k];
            if(abs(num-B) < abs(ans-B)) ans = num;
            if(num == B) return num;
            if(num < B) j++;
            else k--;
        }
    }
    return ans;
}
int main(){
    return 0;
}
