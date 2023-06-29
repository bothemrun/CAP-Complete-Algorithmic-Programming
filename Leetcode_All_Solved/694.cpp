//m0
//use set of vectors of pairs.
//since c++ unordered_set needs custom hashers for vectors.

#define max_n 50
#include<set>
#include<utility>

class Solution {
public:
    int m, n;
    vector<int> di={1, 0, -1, 0};
    vector<int> dj={0, 1, 0, -1};

    void dfs(const vector<vector<int>>& grid, const int& i, const int& j, const int& i0, const int& j0, vector<pair<int,int>>& cells, bool visited[][max_n]){
        if(!(0<=i && i<m && 0<=j && j<n)) return;
        if(grid[i][j] == 0) return;

        if(visited[i][j]) return;
        visited[i][j] = true;

        cells.push_back(pair<int,int>(i - i0, j - j0));
        for(int k=0;k<di.size();k++)
            dfs(grid, i+di[k], j+dj[k], i0, j0, cells, visited);
    }

    int numDistinctIslands(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid.back().size();

        set<vector<pair<int,int>>> setv;
        bool visited[max_n][max_n] = {0};
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)if(grid[i][j]==1 && visited[i][j]==false ){
                vector<pair<int,int>> cells;
                dfs(grid, i, j, i, j, cells, visited);

                setv.insert(cells);
            }
        
        return setv.size();
    }
};
