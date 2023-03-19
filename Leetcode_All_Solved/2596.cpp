#include<stdlib.h>
class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        if(grid[0][0] != 0)return false;
        
        int n = grid.size();
        vector<vector<int>> move(n*n, vector<int>());
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                move[ grid[i][j] ] = vector<int>({i, j});
            }
        }
        
        for(int m=1;m<n*n;m++){
            if(
                ( abs(move[m][0] - move[m-1][0]) == 2 && abs(move[m][1] - move[m-1][1]) == 1 ) ||
                ( abs(move[m][0] - move[m-1][0]) == 1 && abs(move[m][1] - move[m-1][1]) == 2 )
            )continue;
            else return false;
        }
        return true;
    }
};
