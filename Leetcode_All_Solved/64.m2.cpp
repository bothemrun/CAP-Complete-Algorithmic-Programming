//m2
//space optim, alternating vector
#include<algorithm>
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.back().size();
        vector<vector<int>> dp_prev(2, vector<int>(n));
        
        for(int j=0;j<n;j++){
            dp_prev[0][j] = grid[0][j];
            if(j != 0) dp_prev[0][j] += dp_prev[0][j-1];
        }

        for(int i=1;i<m;i++){
            //NOTE: use dp_prev[(i+1)%2],
            //and store in dp_prev[i%2]
            for(int j=0;j<n;j++){
                dp_prev[i%2][j] = grid[i][j];
                
                if(j == 0)
                    dp_prev[i%2][j] += dp_prev[(i+1)%2][j];
                else dp_prev[i%2][j] += min( 
                        dp_prev[i%2][j-1],
                        dp_prev[(i+1)%2][j]
                 );
            }
        }

        return dp_prev[(m-1)%2][n-1];
    }
};
