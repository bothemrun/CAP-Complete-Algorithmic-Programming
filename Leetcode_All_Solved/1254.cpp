class Solution {
private:
    void dfs(vector<vector<int>>& grid,int i,int j, const int& m,const int& n){
        if(!( 0<=i && i<m && 0<=j && j<n && grid[i][j]==0 ))return;
        //visit
        grid[i][j] = 1;
        dfs(grid,i+1,j, m,n);
        dfs(grid,i-1,j, m,n);
        dfs(grid,i,j+1, m,n);
        dfs(grid,i,j-1, m,n);
    }
    void contaminate_boundary_land(vector<vector<int>>& grid,const int& m,const int& n){
        for(int i=0;i<m;i++){
            dfs(grid,i,0, m,n);
            dfs(grid,i,n-1, m,n);
        }
        for(int j=0;j<n;j++){
            dfs(grid,0,j, m,n);
            dfs(grid,m-1,j, m,n);
        }
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        //1.contaminate land cells adjacent to the boundaries
        contaminate_boundary_land(grid,m,n);
        //2.usual counting islands
        int ans = 0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)if(grid[i][j] == 0){
                ans++;
                dfs(grid,i,j, m,n);
            }
        return ans;
    }
};
