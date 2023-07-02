//m0
//binary search the answer, check binary value by dfs.
//O(mnlog(mn)), since the largest possible value = 1e9 is too large.

#define max_n 100
#include<algorithm>
#include<assert.h>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int m, n;
    vector<int> di = {1, 0, -1, 0};
    vector<int> dj = {0, 1, 0, -1};

    bool dfs(const vector<vector<int>>& grid, const int& i, const int& j, bool visited[][max_n], const int& min_bound){

        if(!(0<=i && i<m && 0<=j && j<n)) return false;
        if(grid[i][j] < min_bound) return false;
        if(i==m-1 && j==n-1) return true;

        if(visited[i][j] == true) return false;
        visited[i][j] = true;

        bool res = false;
        for(int k=0;k<di.size();k++)
            res |= dfs(grid, i+di[k], j+dj[k], visited, min_bound);
        return res;
    }

    inline bool good(const vector<vector<int>>& grid, const int& min_bound){
        bool visited[max_n][max_n] = {0};
        return dfs(grid, 0, 0, visited, min_bound);
    }

    int binary(const vector<vector<int>>& grid, const int& low, const int& high){
        int mid = low + (high-low)/2;
        int mid_good = good(grid, mid);
        if(mid_good && good(grid, mid+1) == false) return mid;
        if(low == high) assert(false);

        if(mid_good)
            return binary(grid, mid+1, high);
        else return binary(grid, low, mid);
    }

    int maximumMinimumPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid.back().size();

        int max_grid = grid.front().front();
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                max_grid = max(max_grid, grid[i][j] );

        return binary(grid, 0, max_grid);
    }
};
