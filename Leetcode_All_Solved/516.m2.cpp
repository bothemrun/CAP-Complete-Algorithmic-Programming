//m2

class Solution {
public:
    const int notyet = (-1);
    vector<vector<int>> memo;

    int shrink(const string& s, int i, int j){
        if(!(i<=j)) return 0;

        if(memo[i][j] != notyet) return memo[i][j];

        //1. skip
        int ret = max(
            shrink(s, i+1, j),
            shrink(s, i, j-1)
        ); //(i+1, j-1) skip --> covered

        //2. choose
        if(s[i] == s[j])
            ret = max(
                ret,
                ( (i==j)? 1:2 ) + 
                shrink(s, i+1, j-1)
            );
        
        return memo[i][j] = ret;
    }

    int longestPalindromeSubseq(string s) {
        int n = s.size();

        memo.resize(n, vector<int>(n, notyet));

        return shrink(s, 0, n-1);
    }
};
