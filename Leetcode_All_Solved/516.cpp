//m0
//bottom up DP
#define notyet (-1)
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, notyet));
        for(int i=0;i<n;i++) dp[i][i] = 1;
        
        int max_pal = 1;//for boundaries
        for(int len=2;len<=n;len++){
            for(int low=0;low+(len-1)<n;low++){
                int high = low + (len-1);
                if(len == 2){
                    //NOTE: len 2, (low+1 > high-1)
                    if(s[low] == s[high]){
                        dp[low][high] = 2;
                        max_pal = max(max_pal, 2);
                    }else dp[low][high] = 1;
                }else{
                    if(s[low] == s[high]){
                        /*dp[low][high] = 2 + dp[low+1][high-1];
                        max_pal = max(max_pal, dp[low][high]);*/
                        dp[low][high] = max(2+dp[low+1][high-1], max(dp[low][high-1], dp[low+1][high]) );
                        max_pal = max(max_pal, dp[low][high]);
                    }else dp[low][high] = max(dp[low+1][high-1], max(dp[low][high-1], dp[low+1][high]) );
                }
            }
        }
        
        return max_pal;
    }
};
