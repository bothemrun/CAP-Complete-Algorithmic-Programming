//m1
//NOTE: trap: an encircled island
//NOTE: change color of 1 island to prevent traps of encircled islands

#define color2 2
#define max_n 100
#include<utility>
#include<assert.h>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int n;
    queue<pair<int,int>> q;
    bool inqueue[max_n][max_n] = {0};
    vector<int> di = {1, -1, 0, 0};
    vector<int> dj = {0, 0, 1, -1};

    void dfs_color(vector<vector<int>>& grid, const int& i, const int& j){
        if(!(0<=i && i<n && 0<=j && j<n)) return;
        if(grid[i][j] == 0) return;
        if(inqueue[i][j]) return;

        inqueue[i][j] = true;
        q.push( pair<int,int>(i, j) );
        
        grid[i][j] = color2;

        for(int d=0;d<di.size();d++)
            dfs_color(grid, i+di[d], j+dj[d]);    
    }

    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        bool end_color = false;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)if(grid[i][j]){
                dfs_color(grid, i, j);
                end_color = true;
                break;
            }

            if(end_color) break;
        }

        int level = 0;
        while(q.size()){
            int level_size = q.size();
            for(int l=0;l<level_size;l++){
                auto [i, j] = q.front();
                q.pop();

                for(int d=0;d<di.size();d++){
                    int x = i+di[d];
                    int y = j+dj[d];
                    if(!(0<=x && x<n && 0<=y && y<n)) continue;
                    if(inqueue[x][y]) continue;

                    if(grid[x][y] == 1) return level;

                    inqueue[x][y] = true;
                    q.push( pair<int,int>(x, y) );
                }
            }

            level++;
        }

        assert(false);
        return (-1);
    }
};
