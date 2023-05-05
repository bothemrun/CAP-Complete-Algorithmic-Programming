//m1
//space optim bottom up dp
#define mod ((int)1e9 + 7)
#define IDX(i) ((i+2)%2) //NOTE
#define Memo(i) (memo[ IDX(i) ])
#define max_n ((int)5e4)
#define max_k 50
#include<string.h>
class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid.back().size();
        int memo[2][max_n][max_k] = {0};
        
        Memo(0)[0][ grid[0][0]%k ] = 1;
        int remainder_tmp = grid[0][0]%k;
        for(int j=1;j<n;j++){
            remainder_tmp = (remainder_tmp + grid[0][j])%k;
            Memo(0)[j][ remainder_tmp ] = 1;
        }

        remainder_tmp = grid[0][0]%k;
        for(int i=1;i<m;i++){
            memset(Memo(i)[0], 0, sizeof(Memo(i)[0] ) );
            remainder_tmp = (remainder_tmp + grid[i][0])%k;
            Memo(i)[0][ remainder_tmp ] = 1;

            for(int j=1;j<n;j++)
                for(int r=0;r<k;r++){
                    int need = (r - grid[i][j]%k + k)%k;
                    Memo(i)[j][r] = (
                        Memo(i)[j-1][need] +
                        Memo(i-1)[j][need]
                    )%mod;
                }
        }

        return Memo(m-1)[n-1][0];
    }
};
