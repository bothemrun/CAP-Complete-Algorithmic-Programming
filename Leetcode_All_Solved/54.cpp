#include<utility>
class Solution {
private:
    int m, n;
    vector<vector<bool>> visited;
    vector<int> spiral;
    inline bool legal(int i, int j){
        if( !(0<=i && i<m && 0<=j && j<n) )return false;
        if(visited[i][j])return false;
        return true;
    }
    bool dfs(const vector<vector<int>>& matrix, pair<int,int> pre_dir, int i, int j){
        if(legal(i,j) == false)return false;
        
        visited[i][j] = true;
        spiral.push_back(matrix[i][j]);
        
        //NOTE: keep previuos  direction
        if( dfs(matrix, pre_dir, i+pre_dir.first, j+pre_dir.second) == true) return true;
        
        //NOTE: if not , then only 1 legal direction
        pre_dir = {1,0};
        dfs(matrix, pre_dir, i+pre_dir.first, j+pre_dir.second);
        pre_dir = {-1,0};
        dfs(matrix, pre_dir, i+pre_dir.first, j+pre_dir.second);
        pre_dir = {0,1};
        dfs(matrix, pre_dir, i+pre_dir.first, j+pre_dir.second);
        pre_dir = {0,-1};
        dfs(matrix, pre_dir, i+pre_dir.first, j+pre_dir.second);
        return true;
    }
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        m = matrix.size(), n = matrix[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        dfs(matrix, pair<int,int>({0,1}), 0, 0 );
        return spiral;
    }
};
