//m0

//[A] clipped knapsack dp: dp(i, total rewards upper clipped)

//[B] greedy by sorting

//O(n * max_val + nlogn)

#define max_val 2000

class Solution {
public:
    int n;
    const int notyet = (-1);
    //dp(i, current total rewards upper clipped)
    vector<vector<int>> memo;

    int knapsack_clipped(const vector<int>& rewards, int i, int sum){
        if(i==n) return sum;

        //can't choose anymore
        if(sum >= max_val) return sum;

        if(memo[i][sum] != notyet) return memo[i][sum];

        //choose or skip
        //1. skip
        int ret = knapsack_clipped(rewards, i+1, sum);

        //2. choose
        if(sum < rewards[i]) ret = max(
            ret,
            knapsack_clipped(rewards, i+1, sum + rewards[i])
        );

        return memo[i][sum] = ret;
    }

    int maxTotalReward(vector<int>& rewardValues) {
        n = rewardValues.size();

        sort(rewardValues.begin(), rewardValues.end());

        memo.resize(n, vector<int>(max_val + 1, notyet));

        return knapsack_clipped(rewardValues, 0, 0);
    }
};
