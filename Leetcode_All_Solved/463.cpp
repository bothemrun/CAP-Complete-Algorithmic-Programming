class Solution {
private:
    vector<vector<bool>> visited_land;
    int m, n;
    int perimeter = 0;
    bool dfs(const vector<vector<int>>& grid, int i, int j){
        if(!(0<=i && i<m && 0<=j && j<n))return true;
        if(grid[i][j] == 0)return true;
        
        //now it's land
        if(visited_land[i][j])return false;
        visited_land[i][j] = true;
        perimeter += 
            dfs(grid, i+1, j) +
            dfs(grid, i-1, j) +
            dfs(grid, i, j+1) +
            dfs(grid, i, j-1);
        return false;
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        visited_land = vector<vector<bool>>(m, vector<bool>(n, false));
        for(int i=0;i<m;i++)for(int j=0;j<n;j++)if(grid[i][j]){
            dfs(grid, i, j);
            return perimeter;
        }
        return (-100);//not here
    }
};
