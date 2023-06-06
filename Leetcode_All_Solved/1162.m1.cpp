//m1
//bfs
#define max_n 100
#include<queue>
#include<algorithm>
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
    vector<int> di = {1, -1, 0, 0};
    vector<int> dj = {0, 0, 1, -1};

    int maxDistance(vector<vector<int>>& grid) {
        n = grid.size();

        queue<pair<int,int>> q;
        bool inq[max_n][max_n] = {0};
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)if(grid[i][j] == 1){
                q.push(pair<int,int>(i, j));
                inq[i][j] = true;
            }

        //edge case: all water/land
        if(q.size() == 0 || q.size() == n*n) return (-1);
        

        int level = 0;
        while(q.size()){
            int level_size = q.size();
            for(int k=0;k<level_size;k++){
                auto [i, j] = q.front();
                q.pop();

                for(int d=0;d<di.size();d++){
                    int x = i+di[d];
                    int y = j+dj[d];
                    if(!(0<=x && x<n && 0<=y && y<n)) continue;
                    if(inq[x][y]) continue;
                    assert(grid[x][y] == 0);

                    q.push(pair<int,int>(x, y));
                    inq[x][y] = true;
                }
            }

            level++;
        }

        return level - 1;
    }
};
