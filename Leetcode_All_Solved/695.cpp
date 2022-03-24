class Solution {
private:
    void dfs(int& cur_area, int i, int j, vector<vector<int>>& grid, const int& m, const int& n){
        if(!( 0<=i && i<m && 0<=j && j<n && grid[i][j] == 1 ))return;
        //visit
        grid[i][j] = 0;
        cur_area++;
        dfs(cur_area, i+1, j, grid,m,n);
        dfs(cur_area, i-1, j, grid,m,n);
        dfs(cur_area, i, j+1, grid,m,n);
        dfs(cur_area, i, j-1, grid,m,n);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int max_area = 0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    int cur_area = 0;
                    dfs(cur_area,i,j,grid,m,n);
                    if(cur_area > max_area) max_area = cur_area;
                }
            }
        return max_area;
    }
};
