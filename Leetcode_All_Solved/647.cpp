//m0: bottom up dp
#define notyet (-1)
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, notyet));
        int cnt = 0;
        for(int i=0;i<n;i++){
            dp[i][i] = 1;
            cnt++;
        }

        for(int len=2;len<=n;len++){
            for(int low=0;low+(len-1)<n;low++){
                int high = low + (len-1);
                if(len == 2){//NOTE: len 2, (low+1 > high-1)
                    if(s[low] == s[high]){
                        dp[low][high] = 1;
                        cnt++;
                    }else dp[low][high] = 0;
                }else{
                    if(s[low] == s[high] && dp[low+1][high-1] == 1){
                        dp[low][high] = 1;
                        cnt++;
                    }else{
                        dp[low][high] = 0;
                    }
                }
            }
        }
        return cnt;
    }
};
