class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix.back().size();

        for(int j=0;j<n;j++){
            int ma = (-1);
            for(int i=0;i<m;i++) ma = max(ma, matrix[i][j] );

            for(int i=0;i<m;i++)if(matrix[i][j] == (-1))
                matrix[i][j] = ma;
        }
        return matrix;
    }
};
