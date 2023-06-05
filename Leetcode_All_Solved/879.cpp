//m0
//recursion with memo
#define mod ((int)1e9 + 7)
#define MOD(x) ((x>=mod)? (x-mod):x)
#define notyet (-1)
#include<algorithm>
#include<assert.h>

class Solution {
public:
    int m;
    int maxPeople, minProfit;
    vector<vector<vector<int>>> memo;

    //NOTE: binary tree, subset knapsack
    int subset_knapsack(const vector<int>& group, const vector<int>& profit, const int& i, const int& people, const int& money){
        assert(money <= minProfit);
        if(i == m) return money >= minProfit;

        if(memo[i][people][money] != notyet) return memo[i][people][money];

        //NOTE: not choose
        int cnt = subset_knapsack(group, profit, i+1, people, money);

        if(people + group[i] <= maxPeople)
            cnt = MOD(
                cnt +
                subset_knapsack(group, profit, i+1, people + group[i], min(minProfit, money + profit[i]) )
            );
    
        return memo[i][people][money] = cnt;
    }

    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        m = profit.size();
        maxPeople = n;
        this->minProfit = minProfit;

        memo.resize(m, vector<vector<int>>(maxPeople + 1, vector<int>(minProfit + 1, notyet) ) );

        return subset_knapsack(group, profit, 0, 0, 0);
    }
};
