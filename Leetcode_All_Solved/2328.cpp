//m0
//dfs recursion with memo
//the strict monotone forms a topological sort, dependency and sub-structures
#define mod ((int)1e9 + 7)
#define MOD(x) ( (x>=mod)? (x-mod):x ) //NOTE: mod optim
#define notyet (-1)
class Solution {
public:
    int m, n;
    vector<int> di = {1, -1, 0, 0};
    vector<int> dj = {0, 0, 1, -1};
    vector<vector<int>> memo; //NOTE: count that ends at this

    int dfs_topo(const vector<vector<int>>& grid, const int& i, const int& j, int& all_sum){
        if(memo[i][j] != notyet) return memo[i][j];

        memo[i][j] = 1;

        for(int k=0;k<di.size();k++){
            int x = i+di[k];
            int y = j+dj[k];
            if(!(0<=x && x<m && 0<=y && y<n)) continue;
            if(!(grid[i][j] < grid[x][y] )) continue;

            memo[i][j] = MOD( memo[i][j] + dfs_topo(grid, x, y, all_sum) );
        }
        
        all_sum = MOD( all_sum + memo[i][j] );
        return memo[i][j];
    }

    int countPaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid.back().size();
        
        memo.resize(m, vector<int>(n, notyet));
        int all_sum = 0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                dfs_topo(grid, i, j, all_sum);
        return all_sum;
    }
};
