//m0
//recursion with memo. O(n^2). return number of removals.

#define notyet (-1)
#include<algorithm>

class Solution {
public:
    int n;
    vector<vector<int>> memo;
    int removal(const string& s, const int& i, const int& j){
        //NOTE: includes len==2
        if(i>=j) return 0;

        if(memo[i][j] != notyet) return memo[i][j];

        if(s[i] == s[j]) return memo[i][j] = removal(s, i+1, j-1);
        else return memo[i][j] = 1 + min(
            removal(s, i+1, j),
            removal(s, i, j-1)
        );
    }

    bool isValidPalindrome(string s, int k) {
        n = s.size();

        memo.resize(n, vector<int>(n, notyet));
        return removal(s, 0, n-1) <= k;
    }
};
