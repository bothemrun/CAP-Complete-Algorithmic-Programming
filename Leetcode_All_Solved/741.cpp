//m0
//recursion with memo, 2 pickers simultaneously in the the same direction, 3 variables
#define notyet (-1)
#define thorn (-1)
#define max_n 50
#define none INT_MIN
#include<algorithm>
#include<string.h>
#include<limits.h>
class Solution {
public:
    int n;
    int memo[max_n][max_n][max_n];
    int picker2_var3(const vector<vector<int>>& grid, const int& i, const int& j, const int& x){
        int y = i+j - x;
        if(!(0<=i && 0<=j && 0<=x && 0<=y && y<n)) return none;
        if(memo[i][j][x] != notyet) return memo[i][j][x];

        if(grid[i][j] == thorn || grid[x][y] == thorn) return memo[i][j][x] = none;
        if(i==0 && j==0 && x==0) return memo[0][0][0] = grid[0][0];

        int res = max({
            picker2_var3(grid, i-1, j, x-1),
            picker2_var3(grid, i, j-1, x-1),
            picker2_var3(grid, i-1, j, x),
            picker2_var3(grid, i, j-1, x)
        });
        //NOTE: can't return 0 for out of bounds or thorns
        if(res == none) return memo[i][j][x] = none;

        return memo[i][j][x] = res + ( (i==x)? grid[i][j]:( grid[i][j] + grid[x][y] ) );
    }
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        memset(memo, notyet, sizeof(memo));
        int ans = picker2_var3(grid, n-1, n-1, n-1);
        return (ans==none)? 0:ans;
    }
};
