//m0
//problem == find a path from source to destination whose max cell is minimized.

//binary search the answer
// O( log(n^2) * n*n ) = O(n^2 logn)

#define max_n 50
#include<assert.h>

class Solution {
public:
    int n;
    vector<int> dij = {1, 0, -1, 0, 1};

    bool dfs(const vector<vector<int>>& grid, const int& path_max, bool visited[][max_n], const int& i, const int& j){
        if(!(0<=i && i<n && 0<=j && j<n)) return false;

        if(grid[i][j] > path_max) return false;

        if(i==n-1 && j==n-1) return true;

        if(visited[i][j]) return false;
        visited[i][j] = true;

        for(int k=0;k<4;k++){
            bool tmp = dfs(grid, path_max, visited, 
                i + dij[k],
                j + dij[k+1]
            );

            if(tmp) return true;
        }
        return false;
    }

    inline bool good(const vector<vector<int>>& grid, const int& path_max){
        bool visited[max_n][max_n] = {0};
        return dfs(grid, path_max, visited, 0, 0);
    }

    int binary(const vector<vector<int>>& grid, const int& low, const int& high){
        int mid = low + (high-low)/2;

        bool mid_good = good(grid, mid);
        if( !good(grid, mid-1) && mid_good) return mid;
        assert(low != high);

        if(mid_good) return binary(grid, low, mid);
        else return binary(grid, mid+1, high);
    }

    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        return binary(grid, 0, n*n-1);
    }
};
