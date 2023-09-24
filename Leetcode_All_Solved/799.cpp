//m0
//recursion with memo. O(100^2)

#define max_glass 101
#include<assert.h>

class Solution {
public:
    double poured;

    bool done[max_glass][max_glass] = {0};
    double quantity[max_glass][max_glass];

    //excess already divided by 2
    double excess[max_glass][max_glass];

    void pascal(const int& i, const int& j){
        if( !(j <= i && j >= 0) ) return;

        if(done[i][j] == true) return;

        if(i==0){
            done[i][j] = true;

            if(poured == 0){
                quantity[i][j] = 0;
                excess[i][j] = 0;
            }else{
                quantity[i][j] = 1.0;
                excess[i][j] = (poured - 1.0) / 2.0;
            }
            return;
        }

        pascal(i-1, j);
        pascal(i-1, j-1);
        done[i][j] = true;

        double quant =
            ( (i-1>=0)? excess[i-1][j]:0 ) + 
            ( (i-1>=0 && j-1>=0)? excess[i-1][j-1]:0 );
        if(quant >= 1.0){
            quantity[i][j] = 1.0;
            excess[i][j] = (quant - 1.0) / 2.0;
        }else{
            quantity[i][j] = quant;
            excess[i][j] = 0.0;
        }
    }

    double champagneTower(int poured, int query_row, int query_glass) {
        this->poured = (double)poured;

        pascal(query_row, query_glass);
        return quantity[query_row][query_glass];
    }
};
