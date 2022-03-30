class Solution {
private:
    int m, n;
    bool binary_search(const vector<int>& v, const int& target, int low, int high){
        int mid = low + (high-low)/2;
        if(v[mid] == target)return true;//applies for size 1
        if(low == high)return false;
        
        if(v[mid] > target)return binary_search(v, target, low, mid);
        else return binary_search(v, target, mid+1, high);
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        m = matrix.size(), n = matrix[0].size();
        for(int i=0;i<m;i++)if(binary_search(matrix[i], target, 0, n-1))return true;
        return false;
    }
};
