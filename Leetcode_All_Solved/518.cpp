#include<algorithm>
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        //amount >= 0
        dp[0] = 1;
        //so used coins will be non-decreasing
        for(int coin: coins){
            for(int remain=coin;remain<=amount;remain++){
                if(remain-coin >= 0)
                    dp[remain] += dp[remain-coin];
            }
        }
        return dp[amount];
        
        /*vector<vector<int>> dp(amount+1, vector<int>(coins.size(), 0) );
        //amount >= 0
        for(int i=0;i<coins.size();i++) dp[0][i] = 1;
        for(int remain=1;remain<=amount;remain++){
            for(int i=0;i<coins.size();i++){
                for(int j=0;j<=i;j++){
                    if(remain - coins[j] >= 0)
                        dp[remain][i] += dp[remain-coins[j] ][j];
                }
            }
        }
        return dp[amount][coins.size()-1];
        */
    }
};
