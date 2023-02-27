#define NOTYET (-1)
#define MOD ( (long long)(1e9) + 7 )
class Solution {
public:
    long long handshake(vector<long long>& dp, const int& n){
        if(n == 0) return 1;
        if(dp[n] != NOTYET) return dp[n];

        dp[n] = 0;
        for(int k=1;k<n;k+=2)
            dp[n] = ( dp[n] + 
                handshake(dp, (k-1) - 0 ) *
                handshake(dp, (n-1) - k )
            )%MOD;
        return dp[n];
    }
    int numberOfWays(int numPeople) {
        vector<long long> dp(numPeople + 1, NOTYET);
        return (int)handshake(dp, numPeople);
    }
};
