#include<algorithm>
#include<limits.h>
class Solution {
public:
    int min_climb(const vector<int>& cost, vector<int>& dp, int i){
        if(i < 0)return 0;
        if(dp[i] != INT_MAX)return dp[i];
        
        dp[i] = cost[i] + min( min_climb(cost, dp, i-1), min_climb(cost, dp, i-2) );
        return dp[i];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(), INT_MAX);
        min_climb(cost, dp, cost.size() - 1);
        
        return min( dp.back(), dp[dp.size()-2] );
    }
};
