//m0
//recursion with memo. 1st logic.

//NOTE: c* can also be deletion of 'c'
//NOTE: no consecutive * --> p = "a**" is invalid.

#define notyet (-1)
#include<assert.h>
class Solution {
public:
    int m, n;
    string s, p;
    vector<vector<int>> memo;
    bool lcs_match(const int& i, const int& j){
        assert(i<=m && j<=n);

        if(i==m && j==n) return true;
        if(j==n) return false;
        //NOTE: leave i==m for trailing *

        if(memo[i][j] != notyet) return memo[i][j];

        bool match0 = (i<m) && (
            s[i] == p[j] ||
            p[j] == '.'
        );
        bool res = match0 && lcs_match(i+1, j+1);

        //NOTE: use |=
        if(j+1<n && p[j+1] == '*')
            res |= 
            lcs_match(i, j+2) || //c* deletion/skip
            ( match0 && lcs_match(i+1, j) );//c* use 1
        return memo[i][j] = res;
    }
    bool isMatch(string s, string p) {
        m = s.size();
        n = p.size();
        this->s = s;
        this->p = p;

        memo.resize(m + 1, vector<int>(n + 1, notyet) );
        return lcs_match(0, 0);
    }
};
