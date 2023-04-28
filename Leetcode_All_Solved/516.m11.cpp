//m11
//recursion with memo
#define notyet (-1)
#include<algorithm>
class Solution {
public:
    vector<vector<int>> memo;
    int palin(const string& s, const int& i, const int& j){
        if(!(i<=j)) return 0;
        if(memo[i][j] != notyet) return memo[i][j];
        if(i==j) return memo[i][j] = 1;

        if(s[i] == s[j])
            return memo[i][j] = 2 + palin(s, i+1, j-1);
        return memo[i][j] = max(
            palin(s, i, j-1),
            palin(s, i+1, j)
        );
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        memo.resize(n, vector<int>(n, notyet));
        return palin(s, 0, n-1);
    }
};
