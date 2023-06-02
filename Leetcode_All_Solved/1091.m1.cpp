//m1
#define max_n 100
#include<queue>
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
    vector<int> di = {1, -1, 0, 0, 1, 1, -1, -1};
    vector<int> dj = {0, 0, 1, -1, 1, -1, 1, -1};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.back().size();

        queue<pair<int,int>> q;
        bool inq[max_n][max_n] = {0};

        if(grid[0][0] == 1) return (-1);
        q.push(pair<int,int>(0, 0));
        inq[0][0] = true;

        int level = 1;
        while(q.size()){
            int level_size = q.size();
            for(int k=0;k<level_size;k++){
                auto [i, j] = q.front();
                q.pop();
                if(i == m-1 && j == n-1) return level;

                for(int d=0;d<di.size();d++){
                    int x = i+di[d];
                    int y = j+dj[d];
                    if(!(0<=x && x<m && 0<=y && y<n) || grid[x][y]==1) continue;

                    if(inq[x][y]) continue;
                    inq[x][y] = true;

                    q.push(pair<int,int>(x, y));
                }
            }

            level++;
        }

        return (-1);
    }
};
