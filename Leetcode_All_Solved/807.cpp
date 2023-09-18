//O(n^2) greedy

#include<algorithm>

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<int> row_max(n, 0);
        vector<int> col_max(n, 0);

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++){
                row_max[i] = max( row_max[i], grid[i][j] );
                col_max[j] = max( col_max[j], grid[i][j] );
            }
        
        int increase = 0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++){
                increase += min( row_max[i], col_max[j] ) - grid[i][j];
            }
        
        return increase;
    }
};
