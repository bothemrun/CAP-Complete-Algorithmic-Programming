#define notyet (-1)
#include<algorithm>
class Solution {
public:
    int m, n;
    vector<vector<int>> dp;

    int always_above1_dfs(const vector<vector<int>>& dungeon, int i, int j){
        if(!(i<m && j<n))return INT_MAX;
        if(i == m-1 && j == n-1) return dp[i][j] = ( (dungeon[i][j]<0)? (1 - dungeon[i][j]):1 );
        //NOTE: can't have negative or 0 hp

        if(dp[i][j] != notyet)return dp[i][j];

        int right = always_above1_dfs(dungeon, i, j+1);
        int down = always_above1_dfs(dungeon, i+1, j);

        //NOTE: future paths already kept above 1
        if(dungeon[i][j] >= 0) return dp[i][j] = max(1, min(right, down) - dungeon[i][j] );
        else return dp[i][j] = min(right, down) - dungeon[i][j];//NOTE: penalty
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m = dungeon.size();
        n = dungeon.back().size();
        dp = vector<vector<int>>(m, vector<int>(n, notyet));
        int hp = always_above1_dfs(dungeon, 0, 0);
        /*for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                cout << dp[i][j] << ((j==n-1)?'\n':' ');*/
        return hp;
    }
};
