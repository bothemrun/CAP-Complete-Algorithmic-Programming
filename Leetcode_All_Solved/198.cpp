#include<algorithm>
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2));
        //NOTE: [i] 0: not robbed, 1: robbed at i
        dp[0] = {0, nums[0]};//n >= 1
        
        for(int i=1;i<n;i++){
            dp[i][1] = dp[i-1][0] + nums[i];
            dp[i][0] = max(dp[i-1][1], dp[i-1][0]);
        }
        return max(dp[n-1][0], dp[n-1][1]);
    }
};
