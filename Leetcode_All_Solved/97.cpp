//m0
//recursion with memo
//the interleaving condition: if 2 adjacent substrings are from the same string, then just merge them.
#define notyet (-1)
class Solution {
public:
    vector<vector<int>> memo;
    bool interleave(const string& s1, const string& s2, const int& i, const int& j, const string& s3){
        if(i<0 || j<0) return false;
        if(i==0 && j==0) return true;

        if(memo[i][j] != notyet) return memo[i][j];

        //NOTE: all strings 0-indexed
        memo[i][j] = false;
        //if(s1[i-1] == s3[i+j-1])
        if(i-1>=0 && s1[i-1] == s3[i+j-1])
            memo[i][j] |= interleave(s1, s2, i-1, j, s3);
        if(memo[i][j]) return memo[i][j];//prune
        //if(s2[j-1] == s3[i+j-1])
        if(j-1>=0 && s2[j-1] == s3[i+j-1])
            memo[i][j] |= interleave(s1, s2, i, j-1, s3);
        return memo[i][j];
    }
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        if(m+n != s3.size())return false;

        memo.resize(m+1, vector<int>(n+1, notyet) );

        return interleave(s1, s2, m, n, s3);
    }
};
