//m0
//dfs recursion with memo
//strict monotone forms the topological sort, dependency and sub-structures
#define notyet (-1)
#include<algorithm>
class Solution {
public:
    int m, n;
    vector<int> di = {1, -1, 0, 0};
    vector<int> dj = {0, 0, 1, -1};
    vector<vector<int>> memo;
    int dfs_topo(const vector<vector<int>>& matrix, const int& i, const int& j){
        if(memo[i][j] != notyet) return memo[i][j];

        memo[i][j] = 1;
        for(int k=0;k<di.size();k++){
            int x = i+di[k];
            int y = j+dj[k];
            if(!(0<=x && x<m && 0<=y && y<n)) continue;
            if(!(matrix[i][j] > matrix[x][y])) continue;

            memo[i][j] = max(
                memo[i][j],
                1 + dfs_topo(matrix, x, y)
            );
        }
        return memo[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix.back().size();
        memo.resize(m, vector<int>(n, notyet));
        
        int max_path = 0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                max_path = max(
                    max_path,
                    dfs_topo(matrix, i, j)
                );
        return max_path;
    }
};
