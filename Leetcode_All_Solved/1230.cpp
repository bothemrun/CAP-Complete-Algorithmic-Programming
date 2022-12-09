class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        //NOTE: kind of like Knapsack problem, but the overlapping subproblems is more like a memo table
        
        //NOTE: dp_knapsack[i][h] := for tossing / seeing first i coins(1-indexed), with h heads, the probability
        
        //NOTE: dp[i][h] = prob(coin i head) * dp[i-1][h-1] + prob(coin i tail) * dp[i-1][h]

        //NOTE: only lower left matrix meaningful
        //NOTE: dp[i][0] = product of prob(tail) from coin 1~i
        //NOTE: for i == h, dp[i][h] = product of prob(head) from coin 1~i
        //NOTE: since dp[0][0] won't be used, doesn't matter

        int n = prob.size();
        vector<vector<double>> dp_knapsack(n + 1, vector<double>(target + 1));

        dp_knapsack[0][0] = 1.0;//just for calculation
        for(int i=1;i<=n;i++)
            dp_knapsack[i][0] = dp_knapsack[i-1][0] * (1.0 - prob[i-1] );
        
        for(int h=1;h<=target;h++)
            dp_knapsack[h][h] = dp_knapsack[h-1][h-1] * prob[h-1];
        
        //NOTE: i=1, already done, wrong if apply the recursion formula here
        for(int i=2;i<=n;i++){
            for(int h=1;h<=target;h++){
                dp_knapsack[i][h] = dp_knapsack[i-1][h-1] * prob[i-1] + dp_knapsack[i-1][h] * ( 1 - prob[i-1] );
            }
        }

        return dp_knapsack[n][target];
    }
};




