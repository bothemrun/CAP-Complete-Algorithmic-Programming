//1. dp[m][n][difference]
//2. O(mn * 2*(m+n)) = O(1e4 * 2*2e2) = O(4e6)

#define max_n 100
#define max_diff (2*max_n+1)
#define diff_size 2*max_diff
#define offset max_diff

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
    bool done[max_n][max_n][diff_size] = {0};
    bool memo[max_n][max_n][diff_size] = {0};

    bool enum_diff(const vector<vector<int>>& grid, const int& i, const int& j, const int& diff){
        if(i<0 || j<0) return false;

        if(i==0 && j==0){
            if(grid[0][0] == 1)
                return diff == 1;
            else return diff == (-1);
        }

        if(done[i][j][diff + offset] == true)
            return memo[i][j][diff + offset];
        

        done[i][j][diff + offset] = true;

        if(grid[i][j] == 1)
            return memo[i][j][diff + offset] = 
            enum_diff(grid, i-1, j, diff-1) ||
            enum_diff(grid, i, j-1, diff-1);
        else
            return memo[i][j][diff + offset] = 
            enum_diff(grid, i-1, j, diff+1) ||
            enum_diff(grid, i, j-1, diff+1);
    }

    bool isThereAPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid.back().size();

        return enum_diff(grid, m-1, n-1, 0);
    }
};
