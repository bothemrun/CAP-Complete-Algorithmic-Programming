//m0
//basically BFS, with the help of dfs/bfs to get all cells in 0 cost.

#define max_n 100
#define P pair<int,int>
#include<queue>
#include<assert.h>
#include<utility>
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
    vector<int> di = {0, 0, 0, 1, -1};
    vector<int> dj = {0, 1, -1, 0, 0};

    bool dfs_visited[max_n][max_n] = {0};

    void dfs_no_cost(const vector<vector<int>>& grid, const int& i, const int& j, queue<pair<int,int>>& q, bool inq[][max_n]){

        if(!(0<=i && i<m && 0<=j && j<n)) return;

        if(dfs_visited[i][j]) return;
        dfs_visited[i][j] = true;

        assert(inq[i][j] == false);
        q.push( P(i, j) );
        inq[i][j] = true;

        int k = grid[i][j];
        dfs_no_cost(grid, i + di[ k ], j + dj[ k ], q, inq);
    }

    int minCost(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid.back().size();

        queue<pair<int,int>> q;
        bool inq[max_n][max_n] = {0};


        dfs_no_cost(grid, 0, 0, q, inq);

        int level = 0;
        while(q.size()){
            int level_size = q.size();
            for(int l=0;l<level_size;l++){
                //NOTE: can't use (const) reference.
                auto [i, j] = q.front();
                q.pop();

                if(i==m-1 && j==n-1) return level;

                for(int k=1;k<di.size();k++){
                    int x = i+di[k];
                    int y = j+dj[k];
                    if(!(0<=x && x<m && 0<=y && y<n)) continue;
                    if(inq[x][y] == true) continue;

                    assert( k != grid[i][j] );

                    dfs_no_cost(grid, x, y, q, inq);
                }
            }

            level++;
        }

        assert(false);
        return (-1);
    }
};
