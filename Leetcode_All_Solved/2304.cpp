//O(memo to fill) * O(time for each memo) = O(mn) * O(n) = O(50^3) = O(1e5)

#define notyet (-1)

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

    vector<vector<int>> memo;

    int enum_last_cols(const vector<vector<int>>& grid, const vector<vector<int>>& move, const int& i, const int& j){

        if(i==0) return grid[0][j];

        if(memo[i][j] != notyet) return memo[i][j];

        int min_cost = INT_MAX;
        for(int y=0;y<n;y++)
            min_cost = min(
                min_cost,
                enum_last_cols(grid, move, i-1, y) + move[ grid[i-1][y] ][ j ]
            );
        return memo[i][j] = min_cost + grid[i][j];
    }

    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        m = grid.size();
        n = grid.back().size();

        memo.resize(m, vector<int>(n, notyet));
        int min_cost = INT_MAX;
        for(int j=0;j<n;j++)
            min_cost = min(
                min_cost,
                enum_last_cols(grid, moveCost, m-1, j)
            );
        return min_cost;
    }
};
