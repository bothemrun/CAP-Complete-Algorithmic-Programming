//m1

//use path directions as a string like "udrl" for 4 directions.
//but it'll be wrong without the backtracking information.

//so we use "rb" := backtrack to the right.
//so path string like "rudblb" will uniquely determine a shape.

//but the backtracking directions can be determined from previous directions, 
//so we abbreviate them from "rb" to "b"

#define max_n 50
#define backtrack_path 'b'
#include<unordered_set>

class Solution {
public:
    int m, n;
    vector<int> di={1, 0, -1, 0};
    vector<int> dj={0, 1, 0, -1};
    vector<char> dir={'d', 'r', 'u', 'l'};

    bool visited[max_n][max_n] = {0};
    unordered_set<string> path_uset;

    void dfs(const vector<vector<int>>& grid, const int& i, const int& j, string& path){
        if(!(0<=i && i<m && 0<=j && j<n)) return;
        if(grid[i][j]==0) return;
        
        if(visited[i][j]) return;
        visited[i][j] = true;

        for(int k=0;k<di.size();k++){
            path += dir[k];
            dfs(grid, i+di[k], j+dj[k], path);
        }

        path += backtrack_path;
    }

    int numDistinctIslands(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid.back().size();

        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)if(grid[i][j]==1 && visited[i][j]==false ){
                string path = "s";
                dfs(grid, i, j, path);

                path_uset.insert(path);
            }

        return path_uset.size();
    }
};
