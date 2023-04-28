//m3
//space optim bottom up dp.
//square for bottom right at (i, j)

#define IDX(i) ((i+2)%2) //wrong: ((i)%2) (for the edge case: i==0 & call IDX(0) ) or (i%2)
#define Memo(i) (memo[ IDX(i) ])

#include<algorithm>
#define max_len 300

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix.back().size();
        int memo[2][max_len] = {0};//fast init
        int height[max_len] = {0};
        int max_square = 0;

        //already set boundaries, so i=0
        for(int i=0;i<m;i++){
            height[0] = matrix[i][0] == '1';
            Memo(i)[0] = matrix[i][0] == '1';
            int width = matrix[i][0] == '1';//leftward

            //edge case: n == 1
            max_square = max(max_square, Memo(i)[0] );

            for(int j=1;j<n;j++){
                if(matrix[i][j] == '0'){
                    height[j] = 0;
                    width = 0;
                    Memo(i)[j] = 0;
                    continue;
                }

                height[j]++;
                width++;
                Memo(i)[j] = min({ height[j], width, 1 + Memo(i-1)[j-1] });

                max_square = max(max_square, Memo(i)[j] );
            }
        }

        return max_square * max_square;
    }
};
