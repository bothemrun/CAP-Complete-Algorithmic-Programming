#include<algorithm>
#include<assert.h>
class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.back().size();

        assert(n <= 31);
        int bit_highest = 1 << (n-1);
        int range_mask = ( 1 << (n-1 + 1) ) - 1;
        
        vector<int> row(m, 0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                row[i] = row[i]*2 + grid[i][j];
            }

            //NOTE: precedence: == first, then &: 
            //if( bit_highest & row[i] == 0)
            if( (bit_highest & row[i]) == 0)
                row[i] = ~row[i] & range_mask;
        }

        
        int sum = m * bit_highest;//NOTE: no overflow
        int mask = bit_highest >> 1;
        for(int j=1;j<n;j++){
            int cnt0 = 0, cnt1 = 0;
            for(int i=0;i<m;i++){
                //NOTE: precedence: == first, then &:
                //if(row[i] & mask == 1) cnt1++;
                //NOTE: wrong: if( (row[i] & mask) == 1) cnt1++;
                if( (row[i] & mask) != 0) cnt1++;
                else cnt0++;
            }

            sum += mask * max(cnt0, cnt1);

            mask >>= 1;
        }

        return sum;
    }
};
