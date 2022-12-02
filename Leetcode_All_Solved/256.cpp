#include<algorithm>
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<vector<int>> dp(n, vector<int>(3));
        dp[0] = costs[0];//n>=1
        
        for(int i=1;i<n;i++){
            for(int j=0;j<3;j++)
                dp[i][j] = costs[i][j] + min( dp[i-1][(j+1)%3], dp[i-1][(j+2)%3] );
        }
        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};
