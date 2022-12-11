#include<algorithm>
#include<limits.h>
bool cmp_fn(const int& a, const int& b){
    return a > b;
}
class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid.back().size();
        for(int i=0;i<m;i++){
            sort(grid[i].begin(), grid[i].end(), cmp_fn);
        }
        
        int ans = 0;
        for(int j=0;j<n;j++){
            int max_col = INT_MIN;
            for(int i=0;i<m;i++){
                max_col = max(max_col, grid[i][j]);
            }
            ans += max_col;
        }
        return ans;
    }
};
