#define notyet (-1)
#include<limits.h>
class Solution {
public:
    int dfs(const int& x, vector<int>& dp){
        if(x == 1)return 1;
        assert(x > 1);
        if(dp[x] != notyet)return dp[x];

        dp[x] = INT_MIN;
        for(int y=1;x-y>=1;y++){
            //NOTE: so both y & (x-y) >= 1, at least 2 numbers

            dp[x] = max(dp[x], y * dfs(x-y, dp) );

            //NOTE: but for product of 2 numbers
            dp[x] = max(dp[x], (x-y) * y);
        }
        assert(dp[x] != INT_MIN);//NOTE: or overflow in y * dfs()
        return dp[x];
    }
    int integerBreak(int n) {
        vector<int> dp(n+1, notyet);
        return dfs(n, dp);
    }
};
