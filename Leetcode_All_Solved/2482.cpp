#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.back().size();

        vector<vector<int>> r(m, vector<int>(2, 0));
        vector<vector<int>> c(n, vector<int>(2, 0));

        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                r[i][ grid[i][j] ]++;
                c[j][ grid[i][j] ]++;
            }
        
        vector<vector<int>> ans(m, vector<int>(n));
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                ans[i][j] = r[i][1] + c[j][1] - r[i][0] - c[j][0];
        
        return ans;
    }
};
