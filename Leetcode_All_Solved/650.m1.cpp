//m1
//use DP, not just math
#define test 0
#define MAX (1000*n)
#include<algorithm>
class Solution {
public:
    int minSteps(int n) {
        vector<vector<int>> dp(n+1, vector<int>(1 + (n/2+1), MAX) );
        dp[1][0] = 0;

        for(int ii=2;ii<=n;ii++){
            if(ii%2 == 0){
                //NOTE: dp[2i][i] = min{0 <= k <= i/2, dp[i][k] + 2 }
                // i/2 is floating point division
                int i = ii/2;
                for(int k=0;k <= i/2;k++){
                    dp[2*i][i] = min(
                        dp[2*i][i],
                        dp[i][k] + 2
                    );
                }
            } //else{
            
            //NOTE: dp[i+k][k] = dp[i][k] + 1, 0<k<=i/2, not 0 < k < i/2
            //NOTE: wrong: 2k != i, already done in copy & paste
            //NOTE: 'cuz dp[2k][k] can still paste.
            //NOTE: k != 0, don't paste nothing
            int k = 1;
            while(true){
                int i = ii - k;

                #if test == 1
                printf("ii %d k %d i %d\n", ii, k, i);
                #endif

                //NOTE: if(!(2*k < i))break;
                if(!(2*k <= i))break;

                dp[i+k][k] = dp[i][k] + 1;

                #if test == 1
                printf("ii %d k %d i %d dp[i+k][i] %d\n", ii, k, i, dp[i+k][k]);
                #endif

                k++;
            }
            //}
        }

        #if test == 1
        for(int i=1;i<=n;i++){
            for(int k=0;2*k<=i;k++)
                cout << dp[i][k] << " ";
            cout << endl;
        }
        #endif

        return *min_element(dp[n].begin(), dp[n].end() );


        /*for(int i=1;i<=n;i++){
            //NOTE: dp[i+k][k] = dp[i][k] + 1, 0 < k < i/2
            //NOTE: 2k != i, already done in copy & paste
            //NOTE: k != 0, don't paste nothing
            for(int k=1;2*k < i;k++){
                dp[i+k][k] = dp[i][k] + 1;

                if(i+k == n)return dp[i+k][];
            }

            //NOTE: dp[2i][i] = min{0 <= k <= i/2, dp[i][k] + 2 }
            // i/2 is floating point division
            for(int k=0;2*k<=i;k++){
                dp[2*i][i] = min(
                    dp[2*i][i],
                    dp[i][k] + 2
                );
            }

        }*/
        
    }
};
