//m0
//recursion with memo
#define notyet INT_MIN
#include<algorithm>
#include<limits.h>

class Solution {
public:
    int max_trans;
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
        ); //buy. trans done is counted
        else if(trans < max_trans) ret = max(
            ret,
            stock(prices, i+1, trans+1, true) - prices[i]
        );

        return memo[i][trans][hold] = ret;
    }

    int maxProfit(int k, vector<int>& prices) {
        n = prices.size();
        this->max_trans = k;

        memo.resize(n, vector<vector<int>>(max_trans+1, vector<int>(2, notyet) ) );

        return stock(prices, 0, 0, false);
    }
};
