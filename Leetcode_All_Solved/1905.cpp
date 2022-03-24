class Solution {
private:
    int dfs_sub(const vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j, const int& m, const int& n){
        //0: grid1:n & grid2:y --> falsify all others
        //1: grid1:y & grid2:y --> turns on
        //b'11: not affect results / out of bounds
        if(!( 0<=i && i<m && 0<=j && j<n && grid2[i][j]==1 )) return 3;
        
        int sub = (grid1[i][j]==1)? 1:0;
        grid2[i][j] = 0;//visit, clear
        
        sub &= dfs_sub(grid1,grid2, i+1,j, m,n);
        sub &= dfs_sub(grid1,grid2, i-1,j, m,n);
        sub &= dfs_sub(grid1,grid2, i,j+1, m,n);
        sub &= dfs_sub(grid1,grid2, i,j-1, m,n);
        return sub;
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        //NOTE: grid2 centric; only need to clear grids's land cells
        int m = grid2.size(), n = grid2[0].size();
        int ans = 0;
        for(int i=0;i<m;i++)for(int j=0;j<n;j++)
            if(grid2[i][j] == 1){
                if(dfs_sub(grid1,grid2,i,j,m,n) == 1) ans++;
            }
        return ans;
    }
};
