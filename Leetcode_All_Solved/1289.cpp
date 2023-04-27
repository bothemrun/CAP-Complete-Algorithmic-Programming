//m0
//recursion with memo
#include<algorithm>
#include<limits.h>
#define notyet INT_MAX
class Solution {
public:
    int n;
    vector<vector<int>> memo;
    int fall(const vector<vector<int>>& grid, const int& i, const int& j){
        //NOTE: edge case: n==1
        if(i == n-1) return memo[i][j] = grid[i][j];
        
        if(memo[i][j] != notyet)return memo[i][j];
        
        //already init memo
        for(int col=0;col<n;col++)if(col != j)
            memo[i][j] = min(
                memo[i][j],
                fall(grid, i+1, col) + grid[i][j]
            );
        return memo[i][j];
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        memo = vector<vector<int>>(n, vector<int>(n, notyet));

        for(int j=0;j<n;j++)
            fall(grid, 0, j);
        return *min_element(memo[0].begin(), memo[0].end());
    }
};
