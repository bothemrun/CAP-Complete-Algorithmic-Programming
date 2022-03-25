class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2;i<=n;i++)
            for(int root=1;root<=i;root++)
                dp[i] += dp[root-1] * dp[i-root];
        return dp[n];
    }
};
