class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0;

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                ans += grid[i][j] != 0;

        for(int i=0;i<n;i++){
            int m = 0;
            for(int j=0;j<n;j++)
                m = max(m, grid[i][j]);
            
            ans += m;
        }

        for(int j=0;j<n;j++){
            int m = 0;
            for(int i=0;i<n;i++)
                m = max(m, grid[i][j]);
            
            ans += m;
        }

        return ans;
    }
};
