//m2
//no visited dfs

/*## DFS / BFS For Shortest Path:
- actually not the vanilla dfs / bfs with the visited marks, but we explore all possible paths and prevent infinite loops by stopping extending exploring if  we can’t update it.
- But it may have bad time complexity except for some suitable situations.
- https://stackoverflow.com/a/73823487
	- Ak01 answer: https://stackoverflow.com/questions/14784753/shortest-path-dfs-bfs-or-both
- suitable example: 505. The Maze II
*/
#define max_n 10
#define FRESH INT_MAX
#include<algorithm>
#include<limits.h>

class Solution {
public:
    int m, n;
    vector<int> di={1,0,-1,0};
    vector<int> dj={0,1,0,-1};

    vector<vector<int>> dist;

    void no_visited_dfs_shortest_path(const vector<vector<int>>& grid, const int& i, const int& j, int cur_dist){
        if(!(0<=i && i<m && 0<=j && j<n)) return;
        if(grid[i][j] == 0) return;

        //NOTE: can't improve
        if(!(cur_dist < dist[i][j])) return;

        dist[i][j] = cur_dist;
        for(int k=0;k<di.size();k++)
            no_visited_dfs_shortest_path(grid, i+di[k], j+dj[k], cur_dist + 1);
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid.back().size();
        dist.resize(m, vector<int>(n, FRESH));

        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)if(grid[i][j] == 2)
                no_visited_dfs_shortest_path(grid, i, j, 0);

        
        int max_time = 0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)if(grid[i][j] == 1){
                max_time = max(max_time, dist[i][j] );
            }
        
        return (max_time==FRESH)? (-1):max_time;
    }
};
