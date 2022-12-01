//m1
#include<limits.h>
#include<algorithm>
class Solution {
public:
    int climb(int n, vector<int>& dp, int i){
        if(i < 0)return 0;
        if(i == 0)return 1;
        if(dp[i] != INT_MAX)return dp[i];
        
        dp[i] = climb(n, dp, i-1) + climb(n, dp, i-2);
        return dp[i];
    }
    int climbStairs(int n) {
        vector<int> dp(n + 1, INT_MAX);
        return climb(n, dp, n);
    }
};
