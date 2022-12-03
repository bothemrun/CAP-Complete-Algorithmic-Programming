#include<limits.h>
#include<algorithm>
#include<assert.h>
class Solution {
public:
    int min_jump(const vector<int>& nums, int i, vector<int>& dp){
        if(i >= nums.size()-1)return 0;
        if(dp[i] != INT_MAX)return dp[i];
        
        for(int j=1;j<=nums[i];j++){
            int next = min_jump(nums, i+j, dp);
            if(next != INT_MAX) dp[i] = min(dp[i], 1 + next);
        }
        return dp[i];//maybe INT_MAX
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), INT_MAX);
        int jumps = min_jump(nums, 0, dp);
        assert(jumps != INT_MAX);
        return jumps;
    }
};
