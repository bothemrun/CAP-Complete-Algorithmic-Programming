//m3
//O(n^2 * 26)
#define alphabet (26+1)
#define any_char (alphabet-1)

class Solution {
public:
const int notyet = (-1);
    vector<vector<vector<int>>> memo;
    int shrink_ban(const string& s, int i, int j, char ban_char){
        if(i >= j) return 0;

        if(memo[i][j][ban_char] != notyet) return memo[i][j][ban_char];

        //1. skip
        int ret = max(
            shrink_ban(s, i+1, j, ban_char),
            shrink_ban(s, i, j-1, ban_char)
        );
        //2. choose
        if(s[i] == s[j] && ban_char != s[i]-'a')
            ret = max(
                ret,
                2 + shrink_ban(s, i+1, j-1, s[i] - 'a')
            );
        return memo[i][j][ban_char] = ret;
    }

    int longestPalindromeSubseq(string s) {
        int n = s.size();
        memo.resize(n, vector<vector<int>>(n, vector<int>(alphabet, notyet) ));

        return shrink_ban(s, 0, n-1, any_char);
    }
};
