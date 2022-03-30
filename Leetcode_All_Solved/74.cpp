class Solution {
private:
    int m, n;
    inline int indexing(const vector<vector<int>>& matrix, int k){
        return matrix[k/n][k%n];
    }
    bool binary_search(const vector<vector<int>>& matrix, const int& target, int low, int high){
        int mid = low + (high-low)/2;
        if(indexing(matrix, mid) == target)return true;//applies for size 1
        if(low == high)return false;
        
        if(indexing(matrix, mid) < target)return binary_search(matrix, target, mid+1, high);
        else return binary_search(matrix, target, low, mid);
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        m = matrix.size(), n = matrix[0].size();
        return binary_search(matrix, target, 0, m*n - 1);
    }
};
