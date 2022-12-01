//m1
#include<algorithm>
#include<limits.h>
#include<math.h>
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;//n>=0
        for(int remain=1;remain<=n;remain++)
            for(int coin=1;coin<=sqrt(remain);coin++){
                int square = coin*coin;
                if(remain-square>=0 && dp[remain-square] != INT_MAX)
                    dp[remain] = min(dp[remain], 1 + dp[remain-square]);
            }
        return dp[n];
    }
};
