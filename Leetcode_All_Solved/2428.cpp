class Solution {
public:
    inline long long hourglass(const vector<vector<int>>& grid, const vector<vector<long long>>& prefix, const int& i, const int& j){
        long long sum = prefix[i][j] - grid[i-1][j] - grid[i-1][j-2];
        if(i-3>=0) sum -= prefix[i-3][j];
        if(j-3>=0) sum -= prefix[i][j-3];
        if(i-3>=0 && j-3>=0) sum += prefix[i-3][j-3];
        return sum;
    }

    int maxSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.back().size();
        vector<vector<long long>> prefix(m, vector<long long>(n));
        prefix[0][0] = grid[0][0];
        for(int i=1;i<m;i++)
            prefix[i][0] = prefix[i-1][0] + grid[i][0];
        for(int j=1;j<n;j++)
            prefix[0][j] = prefix[0][j-1] + grid[0][j];
        
        for(int i=1;i<m;i++)
            for(int j=1;j<n;j++)
                prefix[i][j] = grid[i][j] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
        

        long long max_sum = (-1);
        for(int i=2;i<m;i++)
            for(int j=2;j<n;j++)
                max_sum = max(
                    max_sum,
                    hourglass(grid, prefix, i, j)
                );
        
        return (int)max_sum;
    }
};
