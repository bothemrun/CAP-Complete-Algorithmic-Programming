#include<algorithm>
#include<limits.h>
class Solution {
public:
    int m, n;
    vector<int> dirx = {1, -1, 0, 0};
    vector<int> diry = {0, 0, 1, -1};
    void dist_dfs(const vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dist, int cur_dist){
        if(!(0<=i && i<m && 0<=j && j<n))return;
        if(grid[i][j] == 0)return;
        
        //NOTE: stopping condition. watch out adjacent sources --> nonstop stack overflow
        //NOTE: cur_dist == 0 means a source, where rotten oranges may not be sources
        if(grid[i][j] == 2){
            if(cur_dist == 0)dist[i][j] = 0;
            else return;
        }
        if(grid[i][j] == 1){
            if(dist[i][j] <= cur_dist)return;//NOTE: can't improve !!
            else dist[i][j] = cur_dist;
        }
        
        for(int k=0;k<4;k++)
            dist_dfs(grid, i+dirx[k], j+diry[k], dist, cur_dist + 1);
    }
    int orangesRotting(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)if(grid[i][j] == 2)
                dist_dfs(grid, i, j, dist, 0);
        
        int fresh2rotten_max = 0;
        //NOTE: 0: no fresh originally
        //NOTE: INT_MAX: fresh not all went rotten
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)if(grid[i][j] == 1)
                fresh2rotten_max = max(fresh2rotten_max, dist[i][j]);
        if(fresh2rotten_max == INT_MAX)return (-1);
        else return fresh2rotten_max;
    }
};
