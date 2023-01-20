#define dfs_bfs 0 //0 1

#if dfs_bfs == 0

#define notyet (-1)
#include<algorithm>
#include<limits.h>
class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> dir = {
        { {1, 0}, {0, 1} },
        { {-1, 0}, {0, -1} },
        { {1, 0}, {0, -1} },
        { {-1, 0}, {0, 1} }
    };

    int dfs(const vector<vector<int>>& grid, const int& i, const int& j, vector<vector<vector<int>>>& dp, const int& k){
        if(!(0<=i && i<m && 0<=j && j<n)) return INT_MAX;
        if(dp[i][j][k] != notyet) return dp[i][j][k];
        if(grid[i][j] == 1) return 0;

        int min_dist = INT_MAX;
        for(const vector<int>& d: dir[k]){
            int farther_d = dfs(grid, i+d[0], j+d[1], dp, k);
            if(farther_d != INT_MAX)
                min_dist = min(min_dist, 1 + farther_d);
        }
        
        return dp[i][j][k] = min_dist;
    }

    int maxDistance(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid.back().size();

        int max_min_dist = INT_MIN;
        vector<vector<vector<int>>> dp( m, vector<vector<int>>(n, vector<int>(dir.size(), notyet)) );

        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)if(grid[i][j] == 0){
                for(int k=0;k<dir.size();k++){
                    dfs(grid, i, j, dp, k);
                }

                int nearest = *min_element(dp[i][j].begin(), dp[i][j].end());
                if( nearest != INT_MAX )
                    max_min_dist = max(max_min_dist,  nearest);
            }
        
        
        if(max_min_dist == INT_MIN) return (-1);
        return max_min_dist;
    }
};

#endif //dfs_bfs
