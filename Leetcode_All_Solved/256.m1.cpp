//m1
//recursion with memo
#define notyet (-1)
#include<algorithm>
#include<limits.h>
class Solution {
public:
    vector<vector<int>> memo;
    int paint(const vector<vector<int>>& costs, const int& i, const int& state){
        if(i < 0)return 0;
        if(memo[i][state] != notyet)return memo[i][state];

        int cost = INT_MAX;
        for(int j=0;j<3;j++)if(j != state)
            cost = min(cost, costs[i][state] + paint(costs, i-1, j) );
        return memo[i][state] = cost;
    }
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        memo = vector<vector<int>>(n, vector<int>(3, notyet));
        for(int j=0;j<3;j++) paint(costs, n-1, j);

        return *min_element(memo.back().begin(), memo.back().end());
    }
};
