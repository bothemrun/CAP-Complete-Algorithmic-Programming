#include<algorithm>
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix.back().size();

        int max_square = 0;
        vector<int> height(n, 0);
        vector<vector<int>> dp_square(m, vector<int>(n));

        for(int i = 0;i<m;i++){
            //NOTE: leftward width
            int leftward_width = 0;

            for(int j = 0;j<n;j++){
                //NOTE: maintain height
                if(matrix[i][j] == '1') height[j]++;
                else height[j] = 0;

                //NOTE: maintain (leftwards) widith
                if(matrix[i][j] == '1') leftward_width++;
                else leftward_width = 0;

                //NOTE: combine with previous bottom right corner (i, j)
                if(matrix[i][j] == '0') continue;

                //boundary
                if(i == 0 || j == 0){
                    dp_square[i][j] = 1;
                    max_square = max(max_square, dp_square[i][j]);
                }else{
                    dp_square[i][j] = min( 
                        min(height[j], leftward_width),
                        dp_square[i-1][j-1] + 1
                     );
                     
                     max_square = max(max_square, dp_square[i][j] );
                }
            }
        }

        return max_square * max_square;
    }
};
