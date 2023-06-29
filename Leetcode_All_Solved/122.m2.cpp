//m2
//recursion with memo
#define notyet INT_MIN
#include<limits.h>
#include<algorithm>

class Solution {
public:
    int n;
    vector<vector<int>> memo;
    int stock(const vector<int>& prices, const int& i, bool hold){
        if(i==n) return 0;

        if(memo[i][hold] != notyet) return memo[i][hold];

        //not choose
        int ret = stock(prices, i+1, hold);
        //choose
        if(hold==true) //sell
            ret = max(
                ret,
                prices[i] + stock(prices, i+1, false)
            );
        else ret = max(
            ret,
            -prices[i] + stock(prices, i, true)
        );

        return memo[i][hold] = ret;
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        memo.resize(n, vector<int>(2, notyet) );
        return stock(prices, 0, false);
    }
};
