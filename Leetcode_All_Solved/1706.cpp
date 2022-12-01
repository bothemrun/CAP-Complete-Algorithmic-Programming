#define notyet (-2)
class Solution {
public:
    int m, n;
    inline int in_col(int j){
        return (0<=j && j<n);
    }
    int fall_down(const vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp){
        if(in_col(j) == false)return (-1);//include i == m
        if(i == m)return j;
        if(dp[i][j] != notyet) return dp[i][j];
        
        
        int to_i = i+1, to_j, nei_i = i, nei_j;
        if(grid[i][j] == 1){
            to_j = j + 1;
            nei_j = j + 1;
        }else{
            to_j = j - 1;
            nei_j = j - 1;
        }
        
        //check if get stuck
        if(in_col(nei_j)){
            if(grid[i][j] * grid[nei_i][nei_j] == (-1))
                return (dp[i][j] = (-1) );
        }
        
        //checks down
        return ( dp[i][j] = fall_down(grid, to_i, to_j, dp) );
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        vector<int> where_fall(n);
        vector<vector<int>> dp(m, vector<int>(n, notyet));
        
        for(int ball=0;ball<n;ball++){
            where_fall[ball] = fall_down(grid, 0, ball, dp);
        }
        return where_fall;
    }
};
