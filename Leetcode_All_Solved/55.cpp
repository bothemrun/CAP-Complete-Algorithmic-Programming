#define notyet (-1)
class Solution {
public:
    bool jump(const vector<int>& nums, int i, vector<int>& dp){
        if(i >= nums.size()-1)return true;
        if(dp[i] != notyet)return dp[i];
        
        for(int j=1;j<=nums[i];j++)if(jump(nums, i+j, dp) )
            return (dp[i] = true);
        return (dp[i] = false);
    }
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), notyet);
        return jump(nums, 0, dp);
    }
};
