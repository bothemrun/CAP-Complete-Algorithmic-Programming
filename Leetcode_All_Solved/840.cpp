//m0
//brute force in O(mn * 9)

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.back().size();

        int ans = 0;
        for(int i=0;i+2<m;i++)
            for(int j=0;j+2<n;j++){
                int cnt[9+1] = {0};
                bool good = true;
                const int sum = grid[i+0][j] + grid[i+1][j] + grid[i+2][j];

                for(int r=0;r<3;r++){
                    int row_sum = 0;
                    for(int c=0;c<3;c++){
                        const int& g = grid[i+r][j+c];
                        row_sum += g;
                        if(!(1<=g && g<=9)){
                            good = false;
                            break;
                        }
                        if(cnt[g]++ != 0){
                            good = false;
                            break;
                        }
                    }

                    if(row_sum != sum) good = false;

                    if(good==false) break;
                }

                for(int c=0;c<3;c++){
                    int col_sum = 0;
                    for(int r=0;r<3;r++){
                        const int& g = grid[i+r][j+c];
                        col_sum += g;
                    }
                    if(col_sum != sum) good = false;
                }

                int d1 = grid[i+0][j+0] + grid[i+1][j+1] + grid[i+2][j+2];
                int d2 = grid[i+2][j+0] + grid[i+1][j+1] + grid[i+0][j+2];
                if(d1 != sum || d2 != sum) good = false;

                ans += good;
            }
        return ans;
    }
};
