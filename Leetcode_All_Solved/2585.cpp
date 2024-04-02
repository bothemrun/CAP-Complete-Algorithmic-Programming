//classical knapsack dp, not unbounded knapsack
//O(n * target * max count) = O(2.5e6)

class Solution {
public:
    int n;
    const int mod = (int)1e9 + 7;

    const int notyet = (-1);
    vector<vector<int>> memo;

    int knapsack(const vector<vector<int>>& types, const int target, int i, int sum){
        if(i==n) return sum == target;

        assert(i<n && sum<=target);
        if(memo[i][sum] != notyet) return memo[i][sum];

        int ret = 0;
        for(int choose=0, mark=0;choose<=types[i][0];choose++){
            //pruning
            if(sum + mark > target) break;

            ret = (
                ret +
                knapsack(types, target, i+1, sum + mark)
            )%mod;

            mark += types[i][1];
        }

        return memo[i][sum] = ret;
    }

    int waysToReachTarget(int target, vector<vector<int>>& types) {
        this->n = types.size();

        memo.resize(n, vector<int>(target + 1, notyet));
        return knapsack(types, target, 0, 0);
    }
};
