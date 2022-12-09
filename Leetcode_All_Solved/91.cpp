#define notyet (-1)
#include<assert.h>
class Solution {
public:
    vector<string> wordDict;
    int word_break_dfs(const string& s, int high, vector<int>& dp){
        if(high == (-1))return 1;
        assert(high >= 0);
        
        if(dp[high] != notyet)return dp[high];

        dp[high] = 0;
        for(const string& word: wordDict){
            int low = high - (word.size()-1);
            if(low < 0) continue;

            if(word == s.substr(low, word.size()))
                dp[high] += word_break_dfs(s, low-1, dp);
        }
        return dp[high];
    }
    int numDecodings(string s) {
        for(int i=1;i<=26;i++) wordDict.push_back( to_string(i) );

        int n = s.size();
        vector<int> dp(n, notyet);
        //NOTE: dp[i] := number of ways that s[:i] satisfies the segmentation.
        word_break_dfs(s, n-1, dp);
        return dp.back();
    }
};
