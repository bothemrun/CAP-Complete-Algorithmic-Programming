class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target+1, 0);
        dp[0] = 1;
        for(int remain=1;remain<=target;remain++)
            for(int num: nums){
                if(remain-num >= 0) dp[remain] += dp[remain-num];
            }
        return dp[target];
    }
};
