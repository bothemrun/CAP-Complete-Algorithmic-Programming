//top down DP
#define notyet (-1)

class Solution {
public:
    bool dfs(const string& s, int high, vector<int>& dp, const vector<string>& wordDict){
        if(high < 0)return true;
        if(dp[high] != notyet)return dp[high];

        bool ret = false;
        for(const string& word: wordDict){
            int low_tmp = high - (word.size()-1);
            if(low_tmp < 0)continue;
            if(word == s.substr(low_tmp, word.size()) )
                ret |= dfs(s, low_tmp-1, dp, wordDict);
        }

        return (dp[high] = ret);
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> dp(n, notyet);
        //NOTE: dp[i] := s[:i] satisfies the required segmentation
        return dfs(s, n-1, dp, wordDict);
    }
};
