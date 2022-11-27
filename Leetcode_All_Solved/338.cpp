class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 0;
        if(n == 0)return dp;
        dp[1] = 1;
        int mask1 = 1;
        for(int i=2;i<=n;i++){ 
            dp[i] = 1 + dp[ (i & mask1) ];
            if(i == (mask1 << 1)+1 ) mask1 = (mask1 << 1)+1;
        }
        return dp;
    }
};
