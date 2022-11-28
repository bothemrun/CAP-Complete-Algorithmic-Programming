//m1
//bottom up dp
#include<limits.h>
#include<algorithm>
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;//amount >= 0
        for(int remain=1;remain<=amount;remain++){
            for(int& coin: coins){
                if(remain - coin >= 0 && dp[remain-coin] != INT_MAX)
                    dp[remain] = min( dp[remain-coin] + 1, dp[remain]);
            }
        }
        return (dp[amount] == INT_MAX)? (-1):dp[amount];
    }
};
