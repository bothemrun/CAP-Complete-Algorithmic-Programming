//m01
//bottom up, O(n) space, viewpoint from top down dp
#define notyet (-1)
#include<algorithm>
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2,notyet));
        dp[0] = {0, nums[0]};//n>=1
        for(int i=1;i<n;i++){
            dp[i][1] = dp[i-1][0] + nums[i];
            dp[i][0] = max({dp[i-1][0], dp[i-1][1]});
        }
        return max({dp.back()[0], dp.back()[1]});
    }
};
