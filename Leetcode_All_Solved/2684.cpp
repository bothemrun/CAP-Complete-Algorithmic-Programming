#define notyet INT_MIN
#include<limits.h>
#include<algorithm>
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
    vector<vector<int>> memo;
    vector<int> di = {-1, 0, 1};

    int enum3(const vector<vector<int>>& grid, const int& i, const int& j){
        if(j==n-1) return 0;

        if(memo[i][j] != notyet) return memo[i][j];

        int ret = 0;
        for(const int& ddi: di){
            int x = i+ddi;
            int y = j+1;
            if(!( 0<=x && x<m )) continue;
            if(!( grid[i][j] < grid[x][y] )) continue;

            ret = max(
                ret,
                1 + enum3(grid, x, y)
            );
        }

        return memo[i][j] = ret;
    }

    int maxMoves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid.back().size();

        memo.resize(m, vector<int>(n, notyet));
        int ans = 0;
        for(int i=0;i<m;i++)
            ans = max(
                ans,
                enum3(grid, i, 0)
            );
        return ans;
    }
};
