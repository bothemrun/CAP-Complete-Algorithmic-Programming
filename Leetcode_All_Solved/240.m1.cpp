//m1
//PH
//O(m+n), not O(mlogn)
class Solution {
private:
    int m, n;
    bool del_row_col(const vector<vector<int>>& matrix, int target, int i, int j){
        if(!(i<m && 0<=j))return false;
        
        if(matrix[i][j] == target)return true;
        else if(matrix[i][j] < target)return del_row_col(matrix, target, i+1, j);
        else return del_row_col(matrix, target, i, j-1);
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        m = matrix.size(), n = matrix[0].size();
        return del_row_col(matrix, target, 0, n-1);
    }
};
