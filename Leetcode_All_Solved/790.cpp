//NOTE: uva10918 Tri Tiling, poj2411 Mondriaan's Dream
//NOTE: but watch state overlap, not as in Tri Tiling solution.
#define test 0
#define MOD ( (long long)(1e9 + 7) ) //(1e9 + 7)
class Solution {
public:
    int numTilings(int n) {
        const int state_n = 3;
        vector<vector<long long>> dp(n+1, vector<long long>(state_n));
        dp[0] = {1, 0, 0};
        for(int i=1;i<=n;i++){
            if(i-2>=0) dp[i][0] = ( dp[i-1][0] + dp[i-2][0] + dp[i-2][1] + dp[i-2][2] )%MOD;
            else dp[i][0] = dp[i-1][0];

            dp[i][1] = ( dp[i-1][0] + dp[i-1][2] )%MOD;
            dp[i][2] = ( dp[i-1][0] + dp[i-1][1] )%MOD;


            #if test == 1
            for(const int& d: dp[i])
                cout << d << " ";
            cout <<endl;
            #endif
        }
        return dp[n][0];

        
        //NOTE: dp[i+1][0] == dp[i][3] dp states overlap / interfere

        /*const int state_n = 4;
        //NOTE: dp state transistion
        vector<vector<long long>> dp(n+1, vector<long long>(state_n));
        dp[0] = {1, 0, 0, 0};
        for(int i=1;i<=n;i++){
            dp[i][0] = ( dp[i-1][3] + dp[i-1][0] )%MOD;
            dp[i][1] = ( dp[i-1][2] + dp[i-1][0] )%MOD;
            dp[i][2] = ( dp[i-1][1] + dp[i-1][0] )%MOD;
            dp[i][3] = ( dp[i-1][3] + dp[i-1][2] + dp[i-1][1] + dp[i-1][0] )%MOD;

            #if test == 1
            for(const int& d: dp[i])
                cout << d << " ";
            cout <<endl;
            #endif
        }
        return dp[n][0];
        */
    }
};
