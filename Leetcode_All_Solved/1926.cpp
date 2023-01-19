//NOTE: TLE for dfs, going too deep.
#include<queue>
#include<limits.h>
#include<algorithm>
#include<utility>
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze.back().size();

        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int,int>> q;
        q.push( pair<int,int>(entrance[0], entrance[1]) );
        visited[entrance[0]][entrance[1]] = true;
        int level = 0;

        int min_path = INT_MAX;
        
        while(q.size() != 0){
            int level_size = q.size();
            for(int l=0;l<level_size;l++){
                pair<int,int> p = q.front();
                q.pop();
                int i = p.first, j = p.second;
                if( (i == 0 || j == 0 || i == m-1 || j == n-1) && !(i == entrance[0] && j == entrance[1]) ){
                    min_path = min(min_path, level);
                    //NOTE: farther boundary cells won't be smaller.
                    continue;
                }

                for(int k=0;k<dx.size();k++){
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if(!(0<=x && x<m && 0<=y && y<n))continue;
                    if(maze[x][y] == '+')continue;
                    if(visited[x][y])continue;

                    visited[x][y] = true;
                    q.push( pair<int,int>(x, y) );
                }//for k
            }//for l

            level++;
        }//while

        
        if(min_path == INT_MAX)return (-1);
        return min_path;
    }
};

/*
#include<algorithm>
#include<limits.h>
class Solution {
public:
    int m, n;
    int entrance_i, entrance_j;
    bool first = true;
    int min_path = INT_MAX;

    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};

    void dfs(const vector<vector<char>>& maze, vector<vector<bool>>& visited, const int& i, const int& j, const int& dist=0){
        if(!(0<=i && i<m && 0<=j && j<n))return;
        if(maze[i][j] == '+')return;

        if(visited[i][j] == true)return;

        if( (i == 0 || j == 0 || i == m-1 || j == n-1) && first == false ){
            //printf("i %d j %d dist %d\n", i, j, dist);
            min_path = min(min_path, dist);
            //NOTE: don't need to go to other boundary cells farther
            return;
        }
        
        first = false;

        visited[i][j] = true;
        for(int k=0;k<dx.size();k++)
            dfs(maze, visited, i+dx[k], j+dy[k], dist + 1);
        visited[i][j] = false;
    }

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        m = maze.size();
        n = maze.back().size();

        entrance_i = entrance[0];
        entrance_j = entrance[1];

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        dfs(maze, visited, entrance[0], entrance[1]);

        if(min_path == INT_MAX)return (-1);
        return min_path;
    }
};
*/
