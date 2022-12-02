#include<algorithm>
#include<assert.h>
class Solution {
public:
    inline int house_robber(const vector<int>& nums, int low, int high){
        assert(low <= high);
        vector<vector<int>> dp(nums.size(), vector<int>(2));
        dp[low] = {0, nums[low]};//low = 0 or 1
        for(int i=low+1;i<=high;i++){
            dp[i][1] = nums[i] + dp[i-1][0];
            dp[i][0] = max(dp[i-1][1], dp[i-1][0]);
        }
        return max(dp[high][0], dp[high][1]);
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1)return nums[0];
        return max(house_robber(nums, 0, nums.size()-1 - 1), house_robber(nums, 1, nums.size()-1) );
    }
};
