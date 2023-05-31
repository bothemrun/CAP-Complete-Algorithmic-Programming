//m0
//recursion with memo.
#define notyet (-1)
class Solution {
public:
    vector<vector<int>> memo;
    int lcs(const string& s, const string& t, const int& i, const int& j){
        if(j==0) return 1;
        if(i==0) return 0;

        if(memo[i][j] != notyet) return memo[i][j];

        //NOTE: not match this, even if chars match
        memo[i][j] = lcs(s, t, i-1, j);
        //all strings 0-indexed
        if(s[i-1] == t[j-1]) memo[i][j] += lcs(s, t, i-1, j-1);
        return memo[i][j];
    }
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        memo.resize(m + 1, vector<int>(n + 1, notyet));
        return lcs(s, t, m, n);
    }
};
