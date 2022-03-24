class Solution {
private:
    int dfs_count(vector<vector<int>>& grid,int i,int j, const int& m,const int& n){
        if(!( 0<=i && i<m && 0<=j && j<n && grid[i][j] == 1 ))return 0;
        grid[i][j] = 0;//visit
        int count = 1;
        count += dfs_count(grid,i+1,j, m,n);
        count += dfs_count(grid,i-1,j, m,n);
        count += dfs_count(grid,i,j+1, m,n);
        count += dfs_count(grid,i,j-1, m,n);
        return count;
    }
    void contaminate_boundary_land(vector<vector<int>>& grid,const int& m, const int& n){
        for(int i=0;i<m;i++){
            dfs_count(grid,i,0, m,n);
            dfs_count(grid,i,n-1, m,n);
        }
        for(int j=0;j<n;j++){
            dfs_count(grid,0,j, m,n);
            dfs_count(grid,m-1,j, m,n);
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        //1.contaminate land cells adjacent to the boundaries
        contaminate_boundary_land(grid,m,n);
        //2.count all land celss
        int sum = 0;
        for(int i=0;i<m;i++)for(int j=0;j<n;j++)if(grid[i][j] == 1)
            sum += dfs_count(grid,i,j, m,n);
        return sum;
    }
};
