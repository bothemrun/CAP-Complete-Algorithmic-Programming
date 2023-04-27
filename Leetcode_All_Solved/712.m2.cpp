//m2
//recursion with memo
#define notyet (-1)
#include<algorithm>
#include<assert.h>
class Solution {
public:
    vector<vector<int>> memo;
    int edit(const string& s1, const string& s2, const int& i, const int& j){
        //all strings 0-indexed
        assert(i>=0 && j>=0);

        if(memo[i][j] != notyet) return memo[i][j];

        if(i==0 && j==0) return memo[0][0] = 0;
        else if(i == 0) return memo[0][j] = edit(s1, s2, 0, j-1) + s2[j-1];
        else if(j == 0) return memo[i][0] = edit(s1, s2, i-1, 0) + s1[i-1];

        if(s1[i-1] == s2[j-1])
            return memo[i][j] = edit(s1, s2, i-1, j-1);
        return memo[i][j] = min(
            edit(s1, s2, i-1, j) + s1[i-1],
            edit(s1, s2, i, j-1) + s2[j-1]
        );
    }
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        memo = vector<vector<int>>(m+1, vector<int>(n+1, notyet) );
        return edit(s1, s2, m, n);
    }
};
