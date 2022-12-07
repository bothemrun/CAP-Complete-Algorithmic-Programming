//bottom up DP
#define notyet (-1)
#include<algorithm>
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, notyet));
        for(int i=0;i<n;i++) dp[i][i] = 1;

        int max_len = 1;
        int max_low = 0;
        for(int len=2;len<=n;len++){
            for(int low=0;low+(len-1)<n;low++ ){
                int high = low + (len-1);
                //NOTE: length 2 substring
                if(s[low] == s[high] && (low+1==high || dp[low+1][high-1] == 1) ){
                    dp[low][high] = 1;
                    if(max_len < high - (low-1)){
                        max_len = high - (low-1);
                        max_low = low;
                    }
                }else dp[low][high] = 0;
            }
        }
        return s.substr(max_low, max_len);
    }
};
