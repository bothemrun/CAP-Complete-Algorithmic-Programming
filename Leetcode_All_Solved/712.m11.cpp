//m11
//space optim
#define IDX(i) ((i)%2) //wrong: (i%2)
#include<algorithm>
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        vector<vector<int>> memo(2, vector<int>(n+1));

        //NOTE: all strings 0-indexed
        memo[IDX(0)][0] = 0;
        for(int j=1;j<=n;j++) memo[IDX(0)][j] = memo[IDX(0)][j-1] + s2[j-1];

        for(int i=1;i<=m;i++){
            memo[IDX(i)][0] = s1[i-1] + memo[IDX(i-1)][0];
            for(int j=1;j<=n;j++){
                if(s1[i-1] == s2[j-1])
                    memo[IDX(i)][j] = memo[IDX(i-1)][j-1];
                else memo[IDX(i)][j] = min(
                    memo[IDX(i)][j-1] + s2[j-1],
                    memo[IDX(i-1)][j] + s1[i-1]
                );
            }
        }
        return memo[IDX(m)][n];
    }
};
