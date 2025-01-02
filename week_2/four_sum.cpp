//  https://leetcode.com/problems/4sum/



#include <bits/stdc++.h>
using namespace std;
class Solution {

public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        int sze = nums.size();
        for(int i=0;i<sze;++i){
            if(i>0 && nums[i] == nums[i-1]) continue;
            for(int j=i+1;j<sze;++j){
                if(j > i+1 && nums[j]== nums[j-1]) continue;
                int left = j+1;
                int right = sze-1;
                while(left < right){
                    long long sum = nums[i]+nums[j];
                    sum += nums[left];
                    sum += nums[right];
                    if(sum == target){
                        vector<int> temp = {nums[i],nums[j],nums[left],nums[right]};
                        res.push_back(temp);
                         while(left < right &&nums[left] == nums[left+1]) left++;
                        while(left < right && nums[right] == nums[right-1]) right--;
                        left++;
                        right--;
                    }else if(sum < target){
                        left++;
                    }else {
                        right--;
                    }
                } 
            }
        }
        return res;
    }

};

int main(){
    return 0;
}