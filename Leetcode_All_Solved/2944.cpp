#define notyet INT_MIN
#include<limits.h>
class Solution {
public:
    int n;
    vector<int> memo;
    int enum_buy1(const vector<int>& prices, const int& i){
        if(i>=n) return 0;
        
        if(memo[i] != notyet) return memo[i];
        
        int ret = INT_MAX;
        for(int len=1;len<=i+1 + 1;len++){
            //[i+1, i+(i+1)] covered
            //enum buying for covered + next 1 uncovered
            ret = min(
                ret,
                enum_buy1(prices, i+len)
            );
        }
        return memo[i] = ret + prices[i];
    }
    int minimumCoins(vector<int>& prices) {
        n = prices.size();
        memo.resize(n, notyet);
        return enum_buy1(prices, 0);
    }
};
