//NOTE: if the first row is determined, then all rows must be determined.
//NOTE: then afterwards, the remaining rows can be checked 1 by 1 in linear.

//NOTE: use row-oriented for cache locality, instead of column-oriented.

//NOTE: used bitset for optim & convenience.
#define max_size 300
#include<bitset>
class Solution {
public:
    bool removeOnes(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.back().size();

        vector<bitset<max_size>> bits_row(m);
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                bits_row[i][j] = grid[i][j];
        bitset<max_size> mask;
        for(int j=0;j<n;j++) mask[j] = 1;

        
        for(int row0_flip=0;row0_flip<=1;row0_flip++){
            bitset<max_size> flip(bits_row[0]);
            if(row0_flip) flip = ~flip;

            //NOTE: check later rows: row 1 ~ (m-1)
            bool check = true;
            for(int i=1;i<m;i++){
                flip &= mask;
                if(flip == bits_row[i]) continue;
                else if( ( flip ^ bits_row[i] ) == mask ) flip = (~flip) & mask;
                //NOTE: precedence: ^ inferior than ==
                //else if(flip ^ bits_row[i] == mask ) flip = (~flip) & mask;
                else{
                    check = false;
                    break;
                }
            }
            if(check) return true;
        }
        return false;
    }
};
