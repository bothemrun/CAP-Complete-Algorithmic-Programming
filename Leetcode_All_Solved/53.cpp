#include<limits.h>
#include<algorithm>
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> ending_max_dp(nums.size(), INT_MIN);
        ending_max_dp[0] = nums[0];//nums.size() >= 1
        for(int i=1;i<nums.size();i++)
            ending_max_dp[i] = max( ending_max_dp[i-1] + nums[i], nums[i] );
        
        return *max_element(ending_max_dp.begin(), ending_max_dp.end());
    }
};
