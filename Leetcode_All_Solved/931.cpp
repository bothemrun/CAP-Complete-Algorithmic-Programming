#include<limits.h>
class Solution {
public:
    int n;
    int fall(const vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& dp){
        if(!(0<=j && j<n) )return INT_MAX;
        if(i == n)return 0;
        if(dp[i][j] != INT_MAX)return dp[i][j];
        
        for(int j2=j-1;j2<=j+1;j2++){
            int sum = fall(matrix, i + 1, j2, dp);
            if(sum != INT_MAX) dp[i][j] = min(dp[i][j], matrix[i][j] + sum );
        }
        return dp[i][j];
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        for(int j=0;j<n;j++) fall(matrix, 0, j, dp);
        return *min_element(dp[0].begin(), dp[0].end());
    }
};
