//m0

/*## DFS / BFS For Shortest Path:
- actually not the vanilla dfs / bfs with the visited marks, but we explore all possible paths and prevent infinite loops by stopping extending exploring if  we can’t update it.
- But it may have bad time complexity except for some suitable situations.
- https://stackoverflow.com/a/73823487
	- Ak01 answer: https://stackoverflow.com/questions/14784753/shortest-path-dfs-bfs-or-both
- suitable example: 505. The Maze II
*/

//use dfs to find the shortest distance in O(m*n * max(m, n))

//in 490. The Maze, connecting all wall cells is very slow,
//while traversing the cells by 1 step is very fast.
//the reason may be the grid size is quite small.

//so here, we traverse the cells by 1 step and use bfs which is suitable for exploration. O(m*n * (m+n))
#include<limits.h>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int m, n;
    vector<int> di = {1, 0, -1, 0};
    vector<int> dj = {0, 1, 0, -1};

    vector<vector<int>> dist;

    inline void dfs_dist(const vector<vector<int>>& maze, const int& i, const int& j){
        for(int k=0;k<di.size();k++){
            int x = i, y = j;
            int step = 0;
            while(true){
                //candidates
                int a = x+di[k];
                int b = y+dj[k];
                if(!(0<=a && a<m && 0<=b && b<n)) break;
                if(maze[a][b] == 1) break;

                //good, update
                step++;
                x = a;
                y = b;
            }

            if(dist[i][j] + step < dist[x][y]){
                dist[x][y] = dist[i][j] + step;
                dfs_dist(maze, x, y);
            }
        }
    }

    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        m = maze.size();
        n = maze.back().size();
        dist.resize(m, vector<int>(n, INT_MAX));

        dist[start[0]][start[1]] = 0;
        dfs_dist(maze, start[0], start[1]);

        return (dist[destination[0]][destination[1]] == INT_MAX)? (-1):dist[destination[0]][destination[1]];
    }
};
