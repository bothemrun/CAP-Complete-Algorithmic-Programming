//m2
//NOTE: related to loop unrolling, computer architecture.
#include<algorithm>
class Solution {
public:
    //vector<int> dirx = {1, -1, 0, 0};
    //vector<int> diry = {0, 0, 1, -1};
    int m, n;
    /*int backtrack(vector<vector<int>>& grid, const int& i, const int& j){
        if(!(0<=i && i<m && 0<=j && j<n))return 0;
        if(grid[i][j] == 0)return 0;

        int gold = grid[i][j];
        int backtrack_tmp = grid[i][j];
        grid[i][j] = 0;
        
        int max_new_gold = 0;
        max_new_gold = max(max_new_gold ,backtrack(grid, i+1, j) );
        max_new_gold = max(max_new_gold ,backtrack(grid, i-1, j) );
        max_new_gold = max(max_new_gold ,backtrack(grid, i, j+1) );
        max_new_gold = max(max_new_gold ,backtrack(grid, i, j-1) );

        //for(int k=0;k<dirx.size();k++){
            //int x = i + dirx[k];
            //int y = j + diry[k];
            
            //max_new_gold = max(max_new_gold, 
            //    backtrack(grid, x, y)
            //);
        //}

        grid[i][j] = backtrack_tmp;
        return grid[i][j] + max_new_gold;
    }*/

    int max_gold = 0;
    
    void backtrack_parallel(vector<vector<int>>& grid, const int& i, const int& j, int sum=0){
        //NOTE: also use or for faster decision
        if( i<0 || m<=i || j<0 || n<=j || grid[i][j] == 0 ){
            //NOTE: now out of bound or reached no gold
            max_gold = max(max_gold, sum);
            return;
        }

        int backtrack_tmp = grid[i][j];
        grid[i][j] = 0;
        backtrack_parallel(grid, i+1, j, sum + backtrack_tmp);
        backtrack_parallel(grid, i-1, j, sum + backtrack_tmp);
        backtrack_parallel(grid, i, j+1, sum + backtrack_tmp);
        backtrack_parallel(grid, i, j-1, sum + backtrack_tmp);
        grid[i][j] = backtrack_tmp;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid.back().size();
        //int max_gold = 0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)if(grid[i][j] != 0)
                backtrack_parallel(grid, i, j);
                /*max_gold = max(max_gold, 
                    backtrack(grid, i, j)
                );*/
        return max_gold;
    }
};
