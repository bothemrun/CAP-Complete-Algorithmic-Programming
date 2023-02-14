#include<queue>
#include<utility>
#include<assert.h>
class Solution {
public:
    int getFood(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid.back().size();
        int start_i = (-1), start_j = (-1);
        bool found = false;
        for(int i=0;i<m;i++)if(found == false)
            for(int j=0;j<n;j++)if(grid[i][j] == '*'){
                start_i = i;
                start_j = j;
                found = true;
                break;
            }
        assert(start_i >= 0 && start_j >= 0);


        vector<int> di = {1, -1, 0, 0};
        vector<int> dj = {0, 0, 1, -1};

        queue<pair<int,int>> q;
        q.push(pair<int,int>(start_i, start_j));
        vector<vector<bool>> inqueue(m, vector<bool>(n, false));
        inqueue[start_i][start_j] = true;
        
        int level = 1;
        while(q.size() != 0){
            int level_size = q.size();
            for(int l=0;l<level_size;l++){
                auto [i, j] = q.front();
                q.pop();


                for(int k=0;k<di.size();k++){
                    int x = i + di[k];
                    int y = j + dj[k];
                    if(!(0<=x && x<m && 0<=y && y<n)) continue;
                    if(inqueue[x][y] == true) continue;
                    if(grid[x][y] == 'X') continue;

                    if(grid[x][y] == '#') return level;

                    q.push(pair<int,int>(x, y));
                    inqueue[x][y] = true;
                }
            }

            level++;
        }

        return (-1);
    }
};
