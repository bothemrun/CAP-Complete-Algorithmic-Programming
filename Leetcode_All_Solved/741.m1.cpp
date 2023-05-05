//m1
//space optim bottom up dp, 2 pickers simultaneously in the same direction, 3 variables
#define IDX(i) (((i)%2 + 2)%2)
#define Memo(i) (memo[ IDX(i) ])
#define max_n 50
#define thorn (-1)
#define no_path (-1)
#include<assert.h>
#include<algorithm>
class Solution {
public:
    vector<vector<int>> d = {
        {0,-1,0,-1},
        {0,-1,-1,0},
        {-1,0,-1,0},
        {-1,0,0,-1}
    };
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int memo[2][max_n][max_n];

        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        for(int x=0;x<n;x++){
            int y = i+j - x;
            if(!(0<=y && y<n)) continue;

            if(grid[i][j] == thorn || grid[x][y] == thorn){
                Memo(i)[j][x] = no_path;
                continue;
            }

            if(i==0 && j==0 && x==0){
                Memo(0)[0][0] = grid[0][0];
                continue;
            }

            Memo(i)[j][x] = no_path;
            int cherry = (i==x)? grid[i][j]:( grid[i][j] + grid[x][y] );
            for(int k=0;k<d.size();k++){
                int i2 = i+d[k][0];
                int j2 = j+d[k][1];
                int x2 = x+d[k][2];
                int y2 = y+d[k][3];
                if(!(0<=i2 && 0<=j2 && 0<=x2 && 0<=y2)) continue;
                //NOTE: can't use grid[.][.] == thorn, since a non-thorn cell still can have no paths.
                if(Memo(i2)[j2][x2] == no_path) continue;

                Memo(i)[j][x] = max(Memo(i)[j][x], cherry + Memo(i2)[j2][x2] );
            }
        }

        return (Memo(n-1)[n-1][n-1] == no_path)? 0:Memo(n-1)[n-1][n-1];
    }
};
