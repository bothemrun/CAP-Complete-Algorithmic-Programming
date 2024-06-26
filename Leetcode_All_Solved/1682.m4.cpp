//m4
//O(n^2), not O(n^2 * 26)


//[A] for a(sub)a, what if sub has max lengths with both char a & b, will we miss using b as the max substring?

//1. dp(i+1, j) dp(i, j-1) can skip consecutive same chars like:

//a(abcba)a
//#(abcba)a
//a(abcba)#


//2. so the optimal answer may not come from outer a + answer from sub() --> like dp(i, j) = 2 + dp(i+1, j-1)

//3. the optimal answer will come from skipping consecutive same chars --> like dp(i, j) = dp(i, j-1) (skip)

#define tic tuple<int, char>
#include<tuple>

class Solution {
public:
    const tic notyet = tic(-1, -1);
    const tic none = tic(0, 0); //not any char
    vector<vector<tic>> memo;

    tic shrink_skip(const string& s, int i, int j){
        if(i >= j) return none;

        if(memo[i][j] != notyet) return memo[i][j];

        //1. skip
        tic ret = max(
            shrink_skip(s, i+1, j),
            shrink_skip(s, i, j-1)
        );

        //2. choose
        //ok for sizes >= 2
        auto [len, outer_char] = shrink_skip(s, i+1, j-1);
        if(s[i] == s[j] && s[i] != outer_char){
            ret = max(
                ret,
                tic(2 + len, s[i])
            );
        }

        return memo[i][j] = ret;
    }

    int longestPalindromeSubseq(string s) {
        int n = s.size();
        memo.resize(n, vector<tic>(n, notyet));

        return get<0>( shrink_skip(s, 0, n-1) );
    }
};
