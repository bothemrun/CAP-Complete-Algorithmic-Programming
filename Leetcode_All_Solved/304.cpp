class NumMatrix {
private:
    vector<vector<int>> prefix;
    int m, n;
    inline int ext(const int& row, const int& col){
        if(row >= 0 && col >= 0)return prefix[row][col];
        else return 0;
    }
public:
    NumMatrix(vector<vector<int>>& matrix) {
        m = matrix.size(), n = matrix[0].size();
        prefix = vector<vector<int>>(m, vector<int>(n));
        prefix[0][0] = matrix[0][0];
        for(int i=1;i<m;i++)prefix[i][0] = prefix[i-1][0] + matrix[i][0];
        for(int j=1;j<n;j++)prefix[0][j] = prefix[0][j-1] + matrix[0][j];
        for(int i=1;i<m;i++)for(int j=1;j<n;j++)prefix[i][j] = matrix[i][j] - prefix[i-1][j-1] + prefix[i-1][j] + prefix[i][j-1];
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return ext(row2, col2) - ext(row2, col1 - 1) - ext(row1 - 1, col2) + ext(row1 - 1, col1 - 1);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
