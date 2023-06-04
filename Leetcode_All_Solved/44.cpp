//m0
//recursion with memo
#define notyet (-1)
class Solution {
public:
    vector<vector<int>> memo;
    bool lcs(const string& s, const string& p, const int& i, int j){
        if(i==(-1) && j==(-1)) return true;
        //if(i==(-1) || j==(-1)) return false;
        if(j==(-1)) return false;
        if(i==(-1)){
            if(p[j] != '*') return false;

            while(j>=0){
                if(p[j] == '*') j--;
                else return false;
            }
            return true;
        }

        if(memo[i][j] != notyet) return memo[i][j];

        bool ret = false;
        if(s[i] == p[j] || p[j] == '?')
            ret |= lcs(s, p, i-1, j-1);
        
        if(p[j] == '*')
            ret |= lcs(s, p, i-1, j) || lcs(s, p, i, j-1);
        
        return memo[i][j] = ret;
    }
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        memo.resize(m, vector<int>(n, notyet));

        return lcs(s, p, m-1, n-1);
    }
};
