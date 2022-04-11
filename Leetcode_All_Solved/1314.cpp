#include<algorithm>
class Solution {
private:
    vector<vector<int>> prefix_sum;
    int m, n;
    vector<vector<int>> block_sum;
    inline void make_prefix(const vector<vector<int>>& mat){
        prefix_sum[0][0] = mat[0][0];
        for(int i=1;i<m;i++)prefix_sum[i][0] = prefix_sum[i-1][0] + mat[i][0];
        for(int j=1;j<n;j++)prefix_sum[0][j] = prefix_sum[0][j-1] + mat[0][j];
        
        for(int i=1;i<m;i++)for(int j=1;j<n;j++)
            prefix_sum[i][j] = prefix_sum[i][j-1] + prefix_sum[i-1][j] - prefix_sum[i-1][j-1] + mat[i][j];
    }
    
    inline int prefix_sum_(int high_i, int high_j){
        if(high_i < 0 || high_j < 0)return 0;
        return prefix_sum[high_i][high_j];
    }
    inline int block_sum_(int low_i, int low_j, int high_i, int high_j){
        if(high_i < 0 || high_j < 0 || low_i >= m || low_j >= n)return 0;
        //cutoff
        low_i = max(0, low_i);
        low_j = max(0, low_j);
        high_i = min(m-1, high_i);
        high_j = min(n-1, high_j);
        
        return prefix_sum_(high_i,high_j) - prefix_sum_(high_i,low_j - 1) - prefix_sum_(low_i - 1,high_j) + prefix_sum_(low_i - 1,low_j - 1);
    }
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        m = mat.size(), n = mat[0].size();
        prefix_sum = vector<vector<int>>(m, vector<int>(n, 0));
        make_prefix(mat);
        
        block_sum = vector<vector<int>>(m, vector<int>(n, (-1)));
        for(int i=0;i<m;i++)for(int j=0;j<n;j++)
            block_sum[i][j] = block_sum_(i-k, j-k, i+k, j+k);
        return block_sum;
    }
};
