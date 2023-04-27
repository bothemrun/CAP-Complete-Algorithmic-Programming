//m2
//O(1) space bottom up
#define IDX(i) ((i)%2) //wrong: (i%2)
#include<algorithm>
#include<iostream>

static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> memo(2, vector<int>(n+1));

        for(int j=0;j<=n;j++) memo[IDX(0)][j] = j;

        for(int i=1;i<=m;i++){
            memo[IDX(i)][0] = i;

            for(int j=1;j<=n;j++){
                memo[IDX(i)][j] = min( {
                    memo[IDX(i)][j-1] + 1,
                    memo[IDX(i-1)][j] + 1,
                    memo[IDX(i-1)][j-1] + 
                    ( (word1[i-1] == word2[j-1])? 0:1 ) //0-indexed
                } );
            }
        }
        return memo[IDX(m)][n];
    }
};
