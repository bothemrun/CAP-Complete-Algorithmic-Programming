#include<limits.h>
#include<queue>
#include<utility>
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.back().size();

        vector<int> dx = {1, 1, 1, 0, 0, -1, -1, -1};
        vector<int> dy = {1, 0, -1, 1, -1, 1, 0, -1};
        
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        if(grid[0][0] == 1)return (-1);
        q.push( pair<int,int>(0, 0) );
        visited[0][0] = true;

        int level = 1;
        while(q.size() != 0){
            int level_size = q.size();
            for(int l=0;l<level_size;l++){
                pair<int,int> p = q.front();
                q.pop();
                int i = p.first;
                int j = p.second;

                if(i == m-1 && j == n-1)return level;

                for(int k=0;k<dx.size();k++){
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if(!(0<=x && x<m && 0<=y && y<n)) continue;
                    if(visited[x][y] || grid[x][y] == 1) continue;

                    q.push( pair<int,int>(x, y) );
                    visited[x][y] = true;
                }
            }//for l

            level++;
        }

        return (-1);
    }
};
