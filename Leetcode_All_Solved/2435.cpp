//m0
//recursion with memo
#define notyet (-1)
#define mod ((int)1e9 + 7)
class Solution {
public:
    vector<vector<vector<int>>> memo;
    int k;
    int remainder(const vector<vector<int>>& grid, const int& i, const int& j, const int& r){
        if(!(0<=i && 0<=j)) return 0;

        if(memo[i][j][r] != notyet) return memo[i][j][r];
        if(i==0 && j==0) return memo[i][j][r] = r == grid[0][0]%k;

        int need = (r - grid[i][j]%k + k)%k;
        return memo[i][j][r] = (
            remainder(grid, i-1, j, need) +
            remainder(grid, i, j-1, need)
        )%mod;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid.front().size();
        this->k = k;
        memo.resize(m, vector<vector<int>>(n, vector<int>(k, notyet) ) );

        return remainder(grid, m-1, n-1, 0);
    }
};
