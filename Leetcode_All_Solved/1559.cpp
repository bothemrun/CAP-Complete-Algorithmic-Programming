//m0
//dfs acyclic by pre, O(mn)
class Solution {
public:
    int m, n;
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    vector<vector<bool>> visited;
    inline bool legal(const vector<vector<char>>& grid, const int& i, const int& j, const char& c){
        if(!(0<=i && i<m && 0<=j && j<n))return false;
        return c == grid[i][j];
    }
    bool dfs_cyclic(const vector<vector<char>>& grid, const int& i, const int& j, const char& c, int pre_i=(-1), int pre_j=(-1)){
        if(legal(grid, i, j, c) == false)return false;

        if(visited[i][j] == true)return true;
        visited[i][j] = true;

        for(int k=0;k<dx.size();k++){
            int x = i+dx[k];
            int y = j+dy[k];
            if(legal(grid, i, j, c) == false)continue;

            //NOTE: must be here, can be just after the function declaration
            if(pre_i == x && pre_j == y)continue;

            if(dfs_cyclic(grid, x, y, c, i, j) == true)return true;
        }

        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid.back().size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)if(visited[i][j] == false){
                if(dfs_cyclic(grid, i, j, grid[i][j]) == true)return true;
            }
        
        return false;
    }
};
