//m2
//space optim bottom up dp
//square with bottom right at (i, j).

#define IDX(i) ( (i+2)%2 ) //has edge case for i==0 & IDX(i-1): IDX(i) ((i)%2)

#define Memo(i) (memo[ IDX(i) ])
#define Memo_h(i) (memo_h[ IDX(i) ])
#include<algorithm>

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix.back().size();
        vector<vector<int>> memo(2, vector<int>(n, 0));
        vector<vector<int>> memo_h(2, vector<int>(n, 0));
        int max_square = 0;

        //already init boundaries
        for(int i=0;i<m;i++){
            Memo(i)[0] = matrix[i][0] == '1';

            vector<int> width(n);//leftward width
            width[0] = matrix[i][0] == '1';

            //edge case: n==1
            max_square = max(max_square, Memo(i)[0] );

            for(int j=1;j<n;j++){
                if(matrix[i][j] == '0'){
                    Memo(i)[j] = 0;
                    Memo_h(i)[j] = 0;
                    width[j] = 0;
                    continue;
                }

                Memo_h(i)[j] = 1 + Memo_h(i - 1)[j];
                width[j] = 1 + width[j-1];
                
                Memo(i)[j] = min( {
                    1 + Memo(i-1)[j-1],
                    Memo_h(i)[j],
                    width[j]
                } );

                max_square = max(max_square, Memo(i)[j] );
            }
        }

        return max_square * max_square;
    }
};
