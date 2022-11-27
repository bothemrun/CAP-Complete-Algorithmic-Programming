//m1
//space optim
#include<algorithm>
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        for(int j=1;j<=n;j++) dp[j][0] = dp[j-1][0] + s2[j-1];
        for(int i=1;i<=m;i++){
            //NOTE:
            dp[0][ i%2 ] = dp[0][ (i+1)%2 ] + s1[i-1];
            
            for(int j=1;j<=n;j++){
                if(s1[i-1] == s2[j-1]) dp[j][ i%2 ] = dp[j-1][ (i+1)%2 ];
                else dp[j][ i%2 ] = min( dp[j-1][ (i+1)%2 ] + s1[i-1] + s2[j-1], min( dp[j-1][i%2] + s2[j-1], dp[j][ (i+1)%2 ] + s1[i-1] ) );
            }
        }
        return dp[n][ m%2 ];
    }
};
