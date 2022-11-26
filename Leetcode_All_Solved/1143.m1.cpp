//m1
//space optim
#include<algorithm>
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        //NOTE: space optim
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        for(int i = 1;i <= m;i++)
            for(int j = 1;j <= n;j++){
                if(text1[i - 1] == text2[j - 1])
                    dp[j][ i%2 ] = 1 + dp[j-1][ (i+1)%2 ];
                else dp[j][ i%2 ] = max( max(dp[j-1][ i%2 ], dp[j][ (i+1)%2 ]), dp[j-1][ (i+1)%2 ] );
            }
        return dp[ n ][ m%2 ];
    }
};
