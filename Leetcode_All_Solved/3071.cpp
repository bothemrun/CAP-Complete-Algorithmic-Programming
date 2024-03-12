#include<algorithm>

class Solution {
public:
    int n;
    inline bool is_y(const vector<vector<int>>& grid, const int& r, const int& c){
        if(r<n/2){
            return r==c || r+c==n-1;
        }else{
            return c==n/2;
        }
    }

    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        n = grid.size();

        int cnt[2][3] = {0};
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++){
                cnt[ is_y(grid, i, j) ][ grid[i][j] ]++;
            }
        
        const int total_y = n/2+1 + 2*(n/2);
        const int total_other = n*n - total_y;

        int min_op = n*n;
        for(int y=0;y<=2;y++){
            int op = total_y - cnt[1][y];

            int max_other = 0;
            for(int other=0;other<=2;other++)if(other != y){
                max_other = max(max_other, cnt[0][other]);
            }

            op += total_other - max_other;


            min_op = min(min_op, op);
        }

        return min_op;
    }
};
