#include<algorithm>
class Solution {
public:
    int minDistance(string word1, string word2) {
        //NOTE: dp[i][j] := edit dist for w1[0:i-1] and w2[0:j-1]
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        dp[0][0] = 0;
        for(int i=1;i<=m;i++)dp[i][0] = i;
        for(int j=1;j<=n;j++)dp[0][j] = j;
        
        for(int i=1;i<=m;i++)for(int j=1;j<=n;j++)
            dp[i][j] = min( dp[i-1][j-1] + ((word1[i-1]==word2[j-1])?0:1), 1 + min(dp[i-1][j], dp[i][j-1]) );
        return dp[m][n];
    }
};
