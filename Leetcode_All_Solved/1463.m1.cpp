//m1
//space optim bottom up dp
#define IDX(i) ((i+2)%2)
#define Memo(i) (memo[ IDX(i) ])
#define max_n 70
#include<algorithm>
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.back().size();
        int memo[2][max_n][max_n];
        for(int j=0;j<n;j++)
            for(int y=0;y<n;y++)
                Memo(m-1)[j][y] = (j==y)? grid[m-1][j]:(grid[m-1][j] + grid[m-1][y] );
        

        for(int i=m-2;i>=0;i--)
            for(int j=0;j<n;j++)
                for(int y=0;y<n;y++){
                    int ma = 0;
                    int cherry = (j==y)? grid[i][j]:(grid[i][j] + grid[i][y]);
                    for(int dj=(-1);dj<=1;dj++)
                        for(int dy=(-1);dy<=1;dy++){
                            int j2 = j+dj;
                            int y2 = y+dy;
                            if(!(0<=j2 && j2<n && 0<=y2 && y2<n)) continue;
                            ma = max(ma, 
                                Memo(i+1)[j2][y2] + cherry
                            );
                        }
                    Memo(i)[j][y] = ma;
                }
        return Memo(0)[0][n-1];
    }
};
