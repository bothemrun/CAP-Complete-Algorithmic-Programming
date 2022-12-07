//m1
//top down DP, which is trickier and more important
#define notyet (-1)
#include<assert.h>
class Solution {
public:
    int max_pal = 1;//boundaries
    void palindrome_subsequence(const string& s, int low, int high, vector<vector<int>>& dp){
        //NOTE: len 2, (low+1 > high-1)
        if(low-1 == high)return;
        assert(low <= high);

        //NOTE: order is critical
        if(dp[low][high] != notyet)return;
        if(low == high){
            dp[low][high] = 1;//max_pal done
            return;
        }

        palindrome_subsequence(s, low+1, high-1, dp);
        palindrome_subsequence(s, low, high-1, dp);
        palindrome_subsequence(s, low+1, high, dp);
        //dp[low][high] = max( (s[low]==s[high])? 2:0 + dp[low+1][high-1], max(dp[low][high-1], dp[low+1][high]) );
        //NOTE: the precedence of ternary conditional is quite low
        //dp[low][high] = max( ( (s[low]==s[high])? 2:0 ) + dp[low+1][high-1], max(dp[low][high-1], dp[low+1][high]) );
        //NOTE: dp[low+1][high-1] results in low > high for len 2
        dp[low][high] = max( ( (s[low]==s[high])?2:0 ) + ( (low+1==high)? 0:dp[low+1][high-1] ), max(dp[low][high-1], dp[low+1][high]) );

        max_pal = max(max_pal, dp[low][high]);
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, notyet));
        palindrome_subsequence(s, 0, n-1, dp);

        return max_pal;
    }
};
