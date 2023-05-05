//m0
//recursion with memo, 2 pickers, 3 variables
#define notyet (-1)
#include<algorithm>
class Solution {
public:
    vector<vector<vector<int>>> memo;
    int m, n;
    int picker2_var3(const vector<vector<int>>& grid, const int& i, const int& j, const int& y){
        if(!(i<m)) return 0;
        if(memo[i][j][y] != notyet) return memo[i][j][y];

        int m = 0;
        int cherry = (j == y)? grid[i][j]:(grid[i][j] + grid[i][y]);
        for(int dj=(-1);dj<=1;dj++)
            for(int dy=(-1);dy<=1;dy++){
                int j2 = j+dj;
                int y2 = y+dy;
                if(!(0<=j2 && j2<n && 0<=y2 && y2<n)) continue;
                m = max(m,
                    picker2_var3(grid, i+1, j2, y2) + cherry
                );
            }
        return memo[i][j][y] = m;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid.front().size();
        memo.resize(m, vector<vector<int>>(n, vector<int>(n, notyet)) );
        return picker2_var3(grid, 0, 0, n-1);
    }
};
