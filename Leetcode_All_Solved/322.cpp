#include<limits.h>
#include<algorithm>
#include<assert.h>
class Solution {
public:
    //NOTE: INT_MAX: not yet. (-1): impossible
    //NOTE: can't be both inf, or endless loop for top-down dp
    int coin_change(const vector<int>& coins, int remain, vector<int>& dp_memo){
        if(remain < 0)return (-1);//impossible
        if(dp_memo[remain] != INT_MAX)//not yet
            return dp_memo[remain];
        
        int min_change = INT_MAX;
        for(const int& coin: coins){
            int change = coin_change(coins, remain - coin, dp_memo );
            assert(change != INT_MAX);
            if(change != (-1)) min_change = min(min_change, 1 + change);
        }
        if(min_change == INT_MAX)
            return (dp_memo[remain] = (-1) );//impossible
        else return (dp_memo[remain] = min_change ); 
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp_memo(amount + 1, INT_MAX);//not yet
        dp_memo[0] = 0;
        return coin_change(coins, amount, dp_memo);
    }
};
