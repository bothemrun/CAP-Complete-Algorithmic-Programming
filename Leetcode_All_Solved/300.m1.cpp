//m1
//use direct DP
#include<algorithm>
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        //NOTE: dp[i] := lis ending at i
        for(int i=1;i<n;i++)
            for(int j=0;j<i;j++)if(nums[j] < nums[i])
                dp[i] = max(dp[i], 1 + dp[j]);
        return *max_element(dp.begin(), dp.end());
    }
};
