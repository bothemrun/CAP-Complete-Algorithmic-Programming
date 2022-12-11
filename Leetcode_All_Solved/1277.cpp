//NOTE: intuition from 221. Maximal Square
#include<algorithm>
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix.back().size();
        int cnt = 0;

        vector<vector<int>> dp_square(m, vector<int>(n));
        vector<int> height(n, 0);
        for(int i=0;i<m;i++){

            int leftward_width = 0;//NOTE:
            for(int j=0;j<n;j++){
                //NOTE: maintain height
                if(matrix[i][j] == 1) height[j]++;
                else height[j] = 0;

                //NOTE: maintain leftward width, right end at (i, j)
                if(matrix[i][j] == 1)leftward_width++;
                else leftward_width = 0;

                
                //NOTE: dp part
                if(i == 0 || j == 0){//boundary
                    dp_square[i][j] = matrix[i][j];
                }else{
                    dp_square[i][j] = min(1 + dp_square[i-1][j-1], 
                        min(height[j], leftward_width) );
                }

                cnt += dp_square[i][j];
            }
        }

        return cnt;
    }
};
