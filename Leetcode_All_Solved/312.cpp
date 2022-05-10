#include<algorithm>
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        //NOTE: dp[i][j] := balloons in [i,j] popped. enumerate last_pop=i~j
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int l=1;l<=n;l++){
            for(int i=0;i + l-1<n;i++){
                int j = i + l-1;
                
                for(int last_pop=i;last_pop<=j;last_pop++){
                    int outer_left = (i-1>=0)? nums[i-1]:1;
                    int outer_right = (j+1<n)? nums[j+1]:1;
                    dp[i][j] = max(dp[i][j], 
                                  ( (last_pop-1>=i)?dp[i][last_pop-1]:0 ) +
                                  ( (last_pop+1<=j)?dp[last_pop+1][j]:0 ) +
                                  outer_left * nums[last_pop] * outer_right);
                }
            }
        }
        return dp[0][n-1];
    }
};
