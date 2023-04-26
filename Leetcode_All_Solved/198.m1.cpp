//m1
//top down dp
#define notyet (-1)
#include<algorithm>
class Solution {
public:
    vector<vector<int>> memo;
    int rob_dp(const vector<int>& nums, const int& i, const int& rob_this){
        if(i < 0)return 0;
        if(memo[i][rob_this] != notyet)return memo[i][rob_this];

        if(rob_this)
            memo[i][1] = nums[i] + rob_dp(nums, i-1, 0);
        else
            memo[i][0] = max(rob_dp(nums, i-1, 0), rob_dp(nums, i-1, 1));
        return memo[i][rob_this];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        memo.resize(n, vector<int>(2, notyet));
        rob_dp(nums, n-1, 0);
        rob_dp(nums, n-1, 1);

        return max( {memo.back()[0], memo.back()[1]} );
    }
};
