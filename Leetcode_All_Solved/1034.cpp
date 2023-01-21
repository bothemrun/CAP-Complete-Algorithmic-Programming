#include<utility>
class Solution {
public:
    int m, n;
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    vector<pair<int,int>> to_color;

    vector<vector<bool>> visited;
    bool border_dfs(const vector<vector<int>>& grid, const int& i, const int& j, const int& cc_color){
        if(!(0<=i && i<m && 0<=j && j<n))return true;
        if(visited[i][j])return false;
        if(grid[i][j] != cc_color)return true;

        visited[i][j] = true;
        
        for(int k=0;k<dx.size();k++){
            if(border_dfs(grid, i+dx[k], j+dy[k], cc_color) == true){
                to_color.push_back(pair<int,int>(i, j));
            }
        }
        return false;
    }

    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        m = grid.size();
        n = grid.back().size();

        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        border_dfs(grid, row, col, grid[row][col]);

        for(const pair<int,int>& p: to_color)
            grid[p.first][p.second] = color;
        return grid;
    }
};
