//m2
//dp, recursion with memo
#define notyet (-1)
#define max_trans 1
#include<algorithm>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int n;
    //NOTE: memo[i][trans][hold]
    vector<vector<vector<int>>> memo;
    int stock(const vector<int>& prices, const int& i, const int& trans, bool hold){
        if(i==n) return 0;

        if(memo[i][trans][hold] != notyet) return memo[i][trans][hold];

        //not choose
        int ret = stock(prices, i+1, trans, hold);
        
        //choose:
        if(hold == true)//sell
            ret = max(
                ret,
                stock(prices, i+1, trans, false) + prices[i]
            );
        else if(trans < max_trans)//buy
            ret = max(
                ret,
                stock(prices, i+1, trans + 1, true) - prices[i]
            );
        
        return memo[i][trans][hold] = ret;
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        memo.resize(n, vector<vector<int>>(2, vector<int>(2, notyet)) );
        return stock(prices, 0, 0, 0);
    }
};
