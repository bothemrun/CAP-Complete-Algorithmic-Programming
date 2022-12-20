//m3
//NOTE: use bool visited, instead of backtracking on int grid[][]
#include<algorithm>
class Solution {
public:
    vector<int> dirx = {1, -1, 0, 0};
    vector<int> diry = {0, 0, 1, -1};
    int m, n;

    //int backtrack(vector<vector<int>>& grid, const int& i, const int& j){
    
    int backtrack(const vector<vector<int>>& grid, const int& i, const int& j, vector<vector<bool>>& visited){
        //if(!(0<=i && i<m && 0<=j && j<n))return 0;
        //NOTE: use or for faster parallel decision
        
        //if(i<0 || m<=i || j<0 || n<=j || visited[i][j] == true)return 0;
        if(i<0 || m<=i || j<0 || n<=j || visited[i][j] == true || grid[i][j] == 0)return 0;
        //if(grid[i][j] == 0)return 0;
        

        //int backtrack_tmp = grid[i][j];
        //grid[i][j] = 0;
        visited[i][j] = true;
        
        int max_new_gold = 0;
        for(int k=0;k<dirx.size();k++){
            int x = i + dirx[k];
            int y = j + diry[k];
            
            max_new_gold = max(max_new_gold,
                backtrack(grid, x, y, visited)
            );
        }
        //grid[i][j] = backtrack_tmp;
        visited[i][j] = false;

        return grid[i][j] + max_new_gold;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid.back().size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int max_gold = 0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)if(grid[i][j] != 0)
                max_gold = max(max_gold, 
                    backtrack(grid, i, j, visited)
                );
        return max_gold;
    }
};
