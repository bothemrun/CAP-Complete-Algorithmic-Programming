class Solution {
public:
    int countVowelStrings(int n) {
        int m = 5;
        vector<vector<int>> dp(m, vector<int>(n + 1, 0));
        for(int j=0;j<n+1;j++)dp[0][j] = 1;
        for(int i=0;i<m;i++)dp[i][0] = 1;
        
        for(int i=1;i<m;i++)for(int j=1;j<n+1;j++){
            for(int k=0;k<=i;k++)dp[i][j] += dp[k][j-1];
        }
        return dp[m-1][n];//NOTE: trick
    }
};
