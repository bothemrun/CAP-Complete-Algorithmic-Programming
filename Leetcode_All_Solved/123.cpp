//m0
//recursion with memo
#define notyet INT_MIN
#define max_trans 2
#include<limits.h>
#include<algorithm>
#include<assert.h>

class Solution {
public:
    int n;
    vector<vector<vector<int>>> memo;
    int stock(const vector<int>& prices, const int& i, const int& trans, bool hold){
        if(i == n) return 0;

        if(memo[i][trans][hold] != notyet) return memo[i][trans][hold];

        //not choose
        int ret = stock(prices, i+1, trans, hold);

        //sell
        if(hold == true) ret = max(
            ret,
            stock(prices, i+1, trans, false) + prices[i]
        ); //buy. trans done is counted.
        else if(trans < max_trans) ret = max(
            ret,
            stock(prices, i+1, trans+1, true) - prices[i]
        );

        return memo[i][trans][hold] = ret;
    }

    int maxProfit(vector<int>& prices) {
        n = prices.size();
        memo.resize(n, vector<vector<int>>(max_trans+1, vector<int>(2, notyet)) );

        return stock(prices, 0, 0, false);
    }
};
