//m1
//top down DP
#define notyet (-1)
class Solution {
public:
    int n;
    int max_len = 1, max_low = 0;
    bool is_palindrome(const string& s, int low, int high, vector<vector<int>>& dp){
        if(low - 1 == high){//NOTE: length 2 palindrome
            return true;
        }
        if(dp[low][high] != notyet)return dp[low][high];
        if(low == high){
            //NOTE: update max, already done
            return (dp[low][high] = 1);
        }

        if(s[low] == s[high]){
            bool ret = is_palindrome(s, low+1, high-1, dp);
            if(ret == true){
                //NOTE: skip is_pal(low+1, high) & is_pal(low, high-1)
                if(max_len < high-(low-1)){
                    max_len = high - (low-1);
                    max_low = low;
                }
                return (dp[low][high] = 1);
            }
            
        }

        is_palindrome(s, low+1, high, dp);
        is_palindrome(s, low, high-1, dp);
        return (dp[low][high] = 0);
    }
    string longestPalindrome(string s) {
        n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, notyet));
        is_palindrome(s, 0, n-1, dp);
        return s.substr(max_low, max_len);
    }
};
