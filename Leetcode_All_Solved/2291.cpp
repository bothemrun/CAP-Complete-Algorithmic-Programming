//Thinking Process

//[A] Greedy?
//1. sort by profit/cost.
//2. choose from the stocks with the most profit/cost?

//[B] Not Fractional Knapsack.

//[C] Greedy Counterexammple
//1. since it's not fractional, maybe I can use the sub-optimal combination to fill in the remaining budget.
//2. profit = [42, 9, 9, 9, 9, 9] cost = [90, 20, 20, 20, 20, 20], budget=100
//3. profit/cost = [0.46, 0.45, 0.45, 0.45, 0.45, 0.45]
//4. the greedy strategy: +42, choose the last 5: +45
//5. the reason is that we can't fill in the remaining budget
//6. since it's not fractional knapsack.

//[D] so dp
//1. O(n * budget) = O(1e3 * 1e3) = 1e6

//[E] conclusion
//1. simlar: 2431 Maximize Total Tastiness of Purchased Fruits medium
//2. but this is harder since we need to prove the greedy counterexample.

#define notyet INT_MIN
#include<limits.h>
#include<algorithm>

class Solution {
public:
    vector<vector<int>> memo;
    vector<int> gain;

    int choose_or_not(const vector<int>& cost, const int& i, const int& budget){
        if(i==(-1)) return 0;

        if(memo[i][budget] != notyet) return memo[i][budget];

        //skip
        int ret = choose_or_not(cost, i-1, budget);

        //choose
        if(budget >= cost[i])
            ret = max(
                ret,
                gain[i] +
                choose_or_not(cost, i-1, budget - cost[i] )
            );
        
        return memo[i][budget] = ret;
    }

    int maximumProfit(vector<int>& present, vector<int>& future, int budget) {
        int n = present.size();
        gain.resize(n);
        for(int i=0;i<n;i++)
            gain[i] = future[i] - present[i];
        
        memo.resize(n, vector<int>(budget+1, notyet));
        return choose_or_not(present, n-1, budget);
    }
};
