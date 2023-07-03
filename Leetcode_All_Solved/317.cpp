//find distances from houses to lands. 
//--> suitable for this testcase set (more lands than houses).

//NOTE: TLE: find all distance sum of lands to all houses by bfs in o(mn * mn) = O(50^4) = 6e6
//TLE by an edge case that has all of its 1 on the boundaries.

//NOTE: optim:
//1. instead of making an empty bool inq matrix for each bfs,
//we use an int inq: if inq[i][j] == current iteration, then it's been enqueued.


#define max_n 50
#include<queue>
#include<utility>
#include<algorithm>
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
    int m, n;
    vector<int> di={1, 0, -1, 0};
    vector<int> dj={0, 1, 0, -1};

    //NOTE: optim:
    int inq[max_n][max_n] = {0};
    int bfs_cnt = 0;

    int sum[max_n][max_n] = {0};
    int house[max_n][max_n] = {0};
    int total_house;

    inline void bfs_from_house(const vector<vector<int>>& grid, const int& starti, const int& startj){
        //NOTE: optim
        bfs_cnt++;

        queue<pair<int,int>> q;

        q.push(pair<int,int>(starti, startj));
        inq[starti][startj] = bfs_cnt;

        int level = 1;
        while(q.size()){
            int level_size = q.size();
            for(int l=0;l<level_size;l++){
                auto [i, j] = q.front();
                q.pop();

                for(int k=0;k<di.size();k++){
                    int x = i+di[k];
                    int y = j+dj[k];
                    if(!(0<=x && x<m && 0<=y && y<n)) continue;
                    if(inq[x][y] == bfs_cnt) continue;
                    if(grid[x][y] != 0) continue;

                    q.push(pair<int,int>(x, y));
                    inq[x][y] = bfs_cnt;

                    sum[x][y] += level;
                    house[x][y]++;
                }
            }

            level++;
        }
    }

    int shortestDistance(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid.back().size();

        total_house = 0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)if(grid[i][j] == 1){
                total_house++;

                bfs_from_house(grid, i, j);
            }
        

        int min_sum = INT_MAX;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)if(grid[i][j] == 0){
                if(house[i][j] != total_house) continue;

                min_sum = min(min_sum, sum[i][j] );
            }
        
        return (min_sum==INT_MAX)? (-1):min_sum;
    }
};
