//m0
//bottom up DP
#define notyet (-1)
#include<algorithm>

class good{
public:
    int len;
    char endpoint_char;
    //NOTE: since chars of both endpoints are the same
    good(){
        len = 0;
        endpoint_char = 0;//not any of alphabet
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
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<class good>> dp(n, vector<class good>(n, good()) );
        //len 1 done, all 0

        for(int len=2;len<=n;len++){
            for(int low=0;low+(len-1)<n;low++){
                int high = low + (len-1);

                if(len == 2){
                    if(s[low] == s[high])
                        dp[low][high] = good(2, s[low] );
                    //else: still 0
                }else{
                    bool cond0 = ( s[low] == s[high] );
                    bool cond1 = ( s[low] != dp[low+1][high-1].endpoint_char );

                    if(cond0 && cond1){
                        class good good_tmp (2 + dp[low+1][high-1].len, s[low] );
                        dp[low][high] = max( good_tmp, max( dp[low][high-1], dp[low+1][high], cmp_fn ), cmp_fn );
                    }else{
                        dp[low][high] = max( dp[low+1][high-1], max( dp[low][high-1], dp[low+1][high], cmp_fn ), cmp_fn );
                    }
                }

            }
        }

        
        return dp[0][n-1].len;
    }
};



