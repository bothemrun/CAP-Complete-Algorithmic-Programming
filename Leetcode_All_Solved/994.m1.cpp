//m1
//bfs
#define max_n 10
#include<queue>
#include<utility>

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.back().size();
        vector<int> di={1,0,-1,0};
        vector<int> dj={0,1,0,-1};

        queue<pair<int,int>> q;
        bool inq[max_n][max_n] = {0};
        int fresh = 0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1) fresh++;
                else if(grid[i][j] == 2){
                    q.push(pair<int,int>(i, j));
                    inq[i][j] = true;
                }
            }
        
        int level = 0;
        while(q.size()){
            int level_size = q.size();
            for(int l=0;l<level_size;l++){
                auto [i, j] = q.front();
                q.pop();

                for(int k=0;k<di.size();k++){
                    int x=i+di[k];
                    int y=j+dj[k];
                    if(!(0<=x && x<m && 0<=y && y<n)) continue;
                    if(inq[x][y]) continue;
                    if(grid[x][y] != 1) continue;

                    fresh--;
                    q.push(pair<int,int>(x, y));
                    inq[x][y] = true;
                }
            }

            level++;
        }

        //edge: no rotten
        if(level==0) return (fresh==0)? 0:(-1);

        return (fresh==0)? (level-1):(-1);
    }
};
