#define notyet (-1)
#define MOD ((long long)(1e9 + 7))
class Solution {
public:
    vector<string> wordDict;

    inline bool wildcard(const string& word, const string& s){
        //if(word.size() != s.size())return false;
        for(int i=0;i<s.size();i++)
            if(!( (s[i] == '*' && word[i] != '0') || word[i] == s[i]))
                return false;
        //printf("%s %s true\n", word.c_str(), s.c_str());
        return true;
    }

    //int word_break_dfs(const string& s, int high, vector<long long>& dp){
    long long word_break_dfs(const string& s, int high, vector<long long>& dp){
        if(high == (-1))return 1;
        assert(high >= 0);

        if(dp[high] != notyet)return dp[high];

        dp[high] = 0;
        for(const string& word: wordDict){
            int low = high - (word.size()-1);
            if(low < 0) continue;

            if( wildcard(word, s.substr(low, word.size())) )
                dp[high] += word_break_dfs(s, low-1, dp)%MOD;
        }
        return dp[high]%MOD;
    }
    int numDecodings(string s) {
        int n = s.size();
        for(int i=1;i<=26;i++) wordDict.push_back( to_string(i) );

        //vector<int> dp(n, notyet);
        vector<long long> dp(n, notyet);
        //NOTE: dp[i] := number of ways that s[:i] satisfies the requirement.
        return word_break_dfs(s, n-1, dp);
    }
};
