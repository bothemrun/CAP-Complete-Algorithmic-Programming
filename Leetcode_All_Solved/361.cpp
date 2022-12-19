class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid.back().size();
        
        //NOTE: row-wise
        vector<vector<int>> row(m, vector<int>(n));
        for(int i=0;i<m;i++){
            int j=0;
            while(j<n){
                int old_j = j;//NOTE: may be wall
                int enemy = 0;
                while(j<n && grid[i][j] != 'W'){
                    if(grid[i][j] == 'E') enemy++;
                    j++;
                }

                //NOTE: for old_j == wall, still ok
                for(int k=old_j;k<j;k++)//NOTE: may be just 1 wall
                    row[i][k] = enemy;
                
                j++;//NOTE: may be wall for next
            }
        }

        //NOTE: column-wise
        vector<vector<int>> col(m, vector<int>(n));
        for(int j=0;j<n;j++){
            int i=0;
            while(i<m){
                int old_i = i;//NOTE: may be wall
                int enemy = 0;
                while(i<m && grid[i][j] != 'W'){
                    if(grid[i][j] == 'E') enemy++;
                    i++;
                }

                //NOTE: for old_i == wall, still ok
                for(int k=old_i;k<i;k++)//NOTE: may be just 1 wall
                    col[k][j] = enemy;
                
                i++;//NOTE: may be wall for next
            }
        }

        //combine
        int max_enemy = 0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)if(grid[i][j] == '0')
                max_enemy = max(max_enemy, 
                            row[i][j] + col[i][j] );
        return max_enemy;
    }
};


