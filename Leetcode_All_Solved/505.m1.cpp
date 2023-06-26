//m1

/*## DFS / BFS For Shortest Path:

- actually not the vanilla dfs / bfs with the visited marks, but we explore all possible paths and prevent infinite loops by stopping extending exploring if  we can’t update it.

- But it may have bad time complexity except for some suitable situations.

- https://stackoverflow.com/a/73823487

	- Ak01 answer: https://stackoverflow.com/questions/14784753/shortest-path-dfs-bfs-or-both

- suitable example: 505. The Maze II

*/

//use bfs to find the shortest distance in O(m*n * max(m, n))

//in 490. The Maze, connecting all wall cells is very slow,

//while traversing the cells by 1 step is very fast.

//the reason may be the grid size is quite small.

//so here, we traverse the cells by 1 step and use bfs which is suitable for exploration. O(m*n * (m+n))

#include<queue>
#include<utility>
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
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size();
        int n = maze.back().size();
        vector<int> di = {1, 0, -1, 0};
        vector<int> dj = {0, 1, 0, -1};

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        queue<pair<int,int>> q;
        
        dist[start[0]][start[1]] = 0;
        q.push(pair<int,int>(start[0], start[1]));

        while(q.size()){
            int level_size = q.size();
            for(int l=0;l<level_size;l++){
                auto [i, j] = q.front();
                q.pop();

                for(int k=0;k<di.size();k++){
                    int a=i, b=j;
                    int delta = 0;
                    while(true){
                        //candidates
                        int x=a+di[k];
                        int y=b+dj[k];
                        if(!(0<=x && x<m && 0<=y && y<n)) break;
                        if(maze[x][y] == 1) break;

                        //good, update
                        a = x;
                        b = y;
                        delta++;
                    }

                    if(dist[i][j] + delta < dist[a][b] ){
                        dist[a][b] = dist[i][j] + delta;
                        q.push(pair<int,int>(a, b));
                    }
                }
            }
        }

        return (dist[destination[0]][destination[1]]==INT_MAX)? (-1):dist[destination[0]][destination[1]];
    }
};
