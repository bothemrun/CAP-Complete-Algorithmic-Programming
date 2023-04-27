//m1
//recursion with memo
#define notyet (-1)
#include<algorithm>
class Solution {
public:
    vector<vector<int>> memo;
    int edit(const string& word1, const string& word2, const int& i, const int& j){
        if(i == 0 || j == 0)return (i==0)? j:i;
        if(memo[i][j] != notyet)return memo[i][j];

        if(word1[i-1] == word2[j-1])
            return memo[i][j] = edit(word1, word2, i-1, j-1);
        return memo[i][j] = min(
            edit(word1, word2, i-1, j) + 1,
            edit(word1, word2, i, j-1) + 1
        );
    }
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        memo = vector<vector<int>>(m+1, vector<int>(n+1, notyet));
        return edit(word1, word2, m, n);
    }
};
