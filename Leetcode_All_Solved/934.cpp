#include<assert.h>
#include<queue>
#include<utility>
class Solution {
public:
    int n;
    vector<int> di = {1, -1, 0, 0};
    vector<int> dj = {0, 0, 1, -1};
    void island(const vector<vector<int>>& grid, const int& i, const int& j, vector<vector<bool>>& inqueue, queue<pair<int,int>>& q){
        if(!(0<=i && i<n && 0<=j && j<n))return;
        if(grid[i][j] == 0)return;
        if(inqueue[i][j])return;

        inqueue[i][j] = true;
        q.push(pair<int,int>(i, j));

        for(int k=0;k<di.size();k++)
            island(grid, i+di[k], j+dj[k], inqueue, q);
    }
    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        vector<vector<bool>> inqueue(n, vector<bool>(n, false));
        queue<pair<int,int>> q;

        bool end_color = false;
        for(int i=0;i<n;i++)if(end_color == false)
            for(int j=0;j<n;j++)if(grid[i][j] == 1){
                end_color = true;
                island(grid, i, j, inqueue, q);
                break;
            }
        
        int level = 0;
        while(q.size() != 0){
            int level_size = q.size();
            for(int l=0;l<level_size;l++){
                auto [i, j] = q.front();
                q.pop();
                
                for(int k=0;k<di.size();k++){
                    int x = i + di[k];
                    int y = j + dj[k];
                    if(!(0<=x && x<n && 0<=y && y<n))continue;
                    if(inqueue[x][y])continue;
                    if(grid[x][y] == 1)return level;

                    q.push(pair<int,int>(x, y));
                    inqueue[x][y] = true;
                }
            }
            level++;
        }

        assert(false);
        return (-1);
    }
};
