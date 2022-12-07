//m1
//top down DP is trickier and maybe more important
#define notyet (-1)
#include<assert.h>
class Solution {
public:
    int cnt = 0;
    int n;
    bool is_palindrome(const string& s, int low, int high, vector<vector<int>>& dp){
        if(low - 1 == high)return true;//NOTE: length 2, (low > high)
        assert(low <= high);
        if(dp[low][high] != notyet)return dp[low][high];
        //NOTE: the order is crucial
        if(low == high){
            cnt++;
            return (dp[low][high] = 1);
        }

        //NOTE: won't repeat counting
        bool ret = is_palindrome(s, low+1, high-1, dp);
        is_palindrome(s, low, high-1, dp);
        is_palindrome(s, low+1, high, dp);
        if(ret && s[low] == s[high]){
            cnt++;
            return (dp[low][high] = 1);
        }else return (dp[low][high] = 0);
    }
    int countSubstrings(string s) {
        n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, notyet));

        is_palindrome(s, 0, n-1, dp);
        return cnt;
    }
};
