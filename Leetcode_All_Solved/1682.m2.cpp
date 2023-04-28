//m2
//recursion with memo

//why don't have to care about endpoint char comparison?  for eg., a(abab)a
//proof: the inner aa or bb have different index pairs, so the outer a...a can still enumerate both of them correctly.

//if the inner longest has the same end char as the outer chars, then still ok.
//'cuz if the inner use shorter length but different end chars, then the whole length still optim.

#define notyet ( pair<int,char>(-1, 0) )
#define none ( pair<int,char>(0, 0) )
#include<utility>
#include<algorithm>

bool cmp_fn(const pair<int,char>& a, const pair<int,char>& b){
    return a.first < b.first;
}

class Solution {
public:
    vector<vector<pair<int, char>>> memo;
    pair<int, char> palin(const string& s, const int& i, const int& j){
        if(!(i < j)) return none;
        if(memo[i][j] != notyet) return memo[i][j];

        if(i+1 == j) return memo[i][j] = (s[i] == s[j])? pair<int,char>(2, s[i]):none;

        memo[i][j] = max(
            palin(s, i, j-1),
            palin(s, i+1, j),
            cmp_fn
        );

        pair<int,int> p = palin(s, i+1, j-1);
        if(s[i] == s[j] && ( p.first == 0 || p.second != s[i] ) ) memo[i][j] = max(
            memo[i][j],
            pair<int, char>( 2 + p.first, s[i] ),
            cmp_fn
        );
        return memo[i][j];
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        memo.resize(n, vector<pair<int, char>>(n, notyet) );
        return palin(s, 0, n-1).first;
    }
};
