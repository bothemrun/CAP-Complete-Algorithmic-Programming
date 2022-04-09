class Solution {
private:
    vector<vector<bool>> slash_point;
    int n;
    inline int r2f(int i){
        //NOTE: real point coordinate to fractional coordinate
        return 3*(i); //NOTE: 2*(i);
    }
    
    void dfs(vector<vector<bool>>& visited, int f_i, int f_j, const vector<vector<bool>>& slash_point){
        if( !(0<=f_i && f_i<=r2f(n) && 0<=f_j && f_j<=r2f(n) ) )return;
        if(slash_point[f_i][f_j])return;
        if(visited[f_i][f_j])return;
        
        visited[f_i][f_j] = true;
        dfs(visited, f_i+1, f_j, slash_point);
        dfs(visited, f_i-1, f_j, slash_point);
        dfs(visited, f_i, f_j+1, slash_point);
        dfs(visited, f_i, f_j-1, slash_point);
    }
public:
    int regionsBySlashes(vector<string>& grid) {
        n = grid.size();
        //build graph
        //NOTE: fractional coordinates : (0~3n, 0~3n), fc/2 = real point coordinate
        //NOTE: (0~2n, 0~2n) fractional coordinates don't work. since slash can cut them
        slash_point = vector<vector<bool>>(r2f(n) + 1, vector<bool>(r2f(n) + 1, false));
        for(int i=0;i<n;i++)for(int j=0;j<n;j++){
            if(grid[i][j] == '\\'){
                slash_point[r2f(i)][r2f(j)] = true;
                slash_point[r2f(i+1)][r2f(j+1)] = true;
                
                //slash_point[r2f(i) + 1][r2f(j) + 1] = true;//NOTE: r2f(i+0.5) r2f(j+0.5)
                slash_point[r2f(i) + 1][r2f(j) + 1] = true;//NOTE: r2f(i+1/3) r2f(j+1/3)
                slash_point[r2f(i) + 2][r2f(j) + 2] = true;//NOTE: r2f(i+2/3) r2f(j+2/3)
            }else if(grid[i][j] == '/'){
                slash_point[r2f(i+1)][r2f(j)] = true;
                slash_point[r2f(i)][r2f(j+1)] = true;
                
                //slash_point[r2f(i) + 1][r2f(j) + 1] = true;//NOTE: r2f(i+0.5) r2f(j+0.5)
                slash_point[r2f(i) + 1][r2f(j) + 2] = true;//NOTE: r2f(i+1/3) r2f(j+2/3)
                slash_point[r2f(i) + 2][r2f(j) + 1] = true;//NOTE: r2f(i+2/3) r2f(j+1/3)
            }
        }
        //connected components
        int region = 0;
        vector<vector<bool>> visited(r2f(n) + 1, vector<bool>(r2f(n) + 1, false) );
        for(int f_i=0;f_i<=r2f(n);f_i++)for(int f_j=0;f_j<=r2f(n);f_j++)if(!visited[f_i][f_j] && !slash_point[f_i][f_j]){
            dfs(visited, f_i, f_j, slash_point);
            region++;
        }
        return region;
    }
};
