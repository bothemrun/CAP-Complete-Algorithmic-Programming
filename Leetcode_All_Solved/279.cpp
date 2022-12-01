#include<algorithm>
#include<limits.h>
class Solution {
public:
    int numSquares(int n) {
        vector<int> squares;
        for(int i=1;i*i<=n;i++) squares.push_back(i*i);
        
        //NOTE: now coin change problem
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;//n >= 1
        for(int remain=1;remain<=n;remain++){
            for(int coin: squares){
                if(remain - coin >= 0 && dp[remain - coin] != INT_MAX)
                    dp[remain] = min(dp[remain], dp[remain-coin] + 1);
            }
        }
        return dp[n];
    }
};
