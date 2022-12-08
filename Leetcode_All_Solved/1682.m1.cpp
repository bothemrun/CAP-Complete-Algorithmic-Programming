//m1
//top down DP, which is trickier and important
#define notyet (-1)
#include<algorithm>

class good{
public:
    int len;
    char endpoint_char;
    good(){
        len = 0;
        endpoint_char = 0;//NOTE: so not equal to any alphabet
    }
    good(int len_, char endpoint_char_){
        len = len_;
        endpoint_char = endpoint_char_;
    }
};

bool cmp_fn(const class good& a, const class good& b){
    return a.len < b.len;
}

class Solution {
public:int n;
    void palindrome_subsequence(const string& s, int low, int high, vector<vector<class good>>& dp){
        //NOTE: len 2, low+1 > high-1
        if(low > high)return;
        
        if(dp[low][high].len != notyet)return;
        
        //NOTE: the order is critical
        if(low == high){
            dp[low][high] = good();
            return;
        }
        if(low+1 == high){
            if(s[low] == s[high])
                dp[low][high] = good(2, s[low]);
            else dp[low][high] = good();
            return;
        }

        palindrome_subsequence(s, low+1, high-1, dp);
        palindrome_subsequence(s, low+1, high, dp);
        palindrome_subsequence(s, low, high-1, dp);

        bool cond0 = (s[low] == s[high]);
        bool cond1 = ( s[low] != dp[low+1][high-1].endpoint_char );
        class good good2( 2 + dp[low+1][high-1].len, s[low] );

        dp[low][high] = max( ( (cond0&&cond1)? good2:dp[low+1][high-1] ), max( dp[low+1][high], dp[low][high-1], cmp_fn ), cmp_fn );
    }

    int longestPalindromeSubseq(string s) {
        n = s.size();
        vector<vector<class good>> dp(n, vector<class good>(n, good(notyet, 0)));
        palindrome_subsequence(s, 0, n-1, dp);

        return dp[0][n-1].len;
    }
};






