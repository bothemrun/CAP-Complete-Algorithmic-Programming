//O(mn)
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid.back().size();

        int ans = 0;

        vector<vector<int>> prefix(m, vector<int>(n));
        prefix[0][0] = grid[0][0];
        if(prefix[0][0] <= k) ans++;

        for(int i=1;i<m;i++){
            prefix[i][0] = prefix[i-1][0] + grid[i][0];
            if(prefix[i][0] <= k) ans++;
        }

        for(int j=1;j<n;j++){
            prefix[0][j] = prefix[0][j-1] + grid[0][j];
            if(prefix[0][j] <= k) ans++;
        }

        for(int i=1;i<m;i++)
            for(int j=1;j<n;j++){
                //no overflow
                prefix[i][j] = ( prefix[i-1][j] + prefix[i][j-1] ) + ( -prefix[i-1][j-1] + grid[i][j] );

                if(prefix[i][j] <= k) ans++;
            }
        
        return ans;
    }
};
