static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.back().size();

        int min_r = INT_MAX;
        int max_r = INT_MIN;

        int min_c = INT_MAX;
        int max_c = INT_MIN;

        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)if(grid[i][j]){
                min_r = min(min_r, i);
                max_r = max(max_r, i);

                min_c = min(min_c, j);
                max_c = max(max_c, j);
            }
        
        return (max_r - (min_r-1)) * (max_c - (min_c-1));
    }
};
