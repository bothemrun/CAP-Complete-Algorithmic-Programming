//m0

#define tll tuple<long long, long long>
#define notyet tll(LLONG_MIN, LLONG_MAX)
#include<tuple>
#include<limits.h>
#include<algorithm>

class Solution {
public:
    vector<vector<tll>> memo;
    vector<int> di = {0, -1};
    vector<int> dj = {-1, 0};

    tll enum2(const vector<vector<int>>& grid, const int& i, const int& j){
        if(i==0 && j==0) return {grid[0][0], grid[0][0]};

        if(memo[i][j] != notyet) return memo[i][j];

        const int& g = grid[i][j];
        auto& [ma, mi] = memo[i][j];
        for(int k=0;k<(int)di.size();k++){
            int x = i+di[k];
            int y = j+dj[k];
            if(!(0<=x && 0<=y)) continue;

            const auto& [ma1, mi1] = enum2(grid, x, y);

            if(g >= 0){
                ma = max(ma, g * ma1);
                mi = min(mi, g * mi1);
            }else{
                ma = max(ma, g * mi1);
                mi = min(mi, g * ma1);
            }
        }

        return memo[i][j];
    }

    int maxProductPath(vector<vector<int>>& grid) {
        const long long mod = (long long)1e9 + 7;
        int m = grid.size();
        int n = grid.back().size();

        memo.resize(m, vector<tll>(n, notyet));
        auto [ma, mi] = enum2(grid, m-1, n-1);
        return (ma>=0)? ma%mod:(-1);
    }
};
