class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int neg = 0;
        int j_begin = n;//low, inclusive
        for(int i=0;i<m;i++){
            int j;
            for(j=j_begin-1;j>=0;j--){
                if(grid[i][j] >= 0)break;
            }
            j_begin = j+1;
            neg += n - j_begin;
            
            if(j_begin == 0){
                neg += n * ( m-1 - i );
                break;
            }
        }
        return neg;
    }
};
