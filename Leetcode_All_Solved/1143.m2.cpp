//m2
//recursion with memo
#define notyet (-1)
#include<algorithm>
class Solution {
public:
    vector<vector<int>> memo;
    int lcs(const string& text1, const string& text2, const int& i, const int& j){
        if(i == 0 || j == 0)return 0;//empty string
        if(memo[i][j] != notyet)return memo[i][j];

        memo[i][j] = max(
            lcs(text1, text2, i-1, j),
            lcs(text1, text2, i, j-1)
        );
        if(text1[i-1] == text2[j-1])//NOTE: 0-indexed
            memo[i][j] = max(
                memo[i][j],
                1 + lcs(text1, text2, i-1, j-1)
            );
        return memo[i][j];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        memo = vector<vector<int>>(m+1, vector<int>(n+1, notyet));
        return lcs(text1, text2, m, n);
    }
};
