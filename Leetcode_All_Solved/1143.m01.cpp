//m01
//O(1) space bottom up, but use array instead of vector
#define IDX(i) ((i)%2) //wrong: (i%2)
#define max_len (1000)
#include<algorithm>
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        //vector<vector<int>> memo(2, vector<int>(n+1, 0));
        //int memo[2][n+1] = {0};
        int memo[2][max_len+1] = {0};
        
        for(int i=1;i<=m;i++){
            //memo[*][0] always == 0, already set
            for(int j=1;j<=n;j++){
                memo[IDX(i)][j] = max(
                    memo[IDX(i-1)][j],
                    memo[IDX(i)][j-1]
                );

                if(text1[i-1] == text2[j-1])//0-indexed
                    memo[IDX(i)][j] = max(
                        memo[IDX(i)][j],
                        1 + memo[IDX(i-1)][j-1]
                    );
            }
        }
        return memo[IDX(m)][n];
    }
};
