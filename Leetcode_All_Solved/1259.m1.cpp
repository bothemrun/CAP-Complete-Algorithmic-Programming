//m1
//bottom up dp, O(n^2)
#define MOD ( (long long)(1e9) + 7 )
class Solution {
public:
    int numberOfWays(int numPeople) {
        vector<long long> dp(numPeople +1, 0);
        dp[0] = 1;
        for(int n=2;n<=numPeople;n+=2)
            for(int k=1;k<n;k+=2)
                dp[n] = (
                    dp[n] +
                    dp[ (k-1) - 0 ] *
                    dp[ (n-1) - k ]
                )%MOD;
        return (int)dp[numPeople];
    }
};
