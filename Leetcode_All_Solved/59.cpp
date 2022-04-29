#include<utility>
class Solution {
private:
    vector<vector<int>> spiral;
    int n;
    vector<vector<bool>> visited;
    inline bool legal(int i, int j){
        if( !(0<=i && i<n && 0<=j && j<n) )return false;
        if(visited[i][j])return false;
        return true;
    }
    bool dfs(int i, int j, pair<int,int> pre_dir, int val=1){
        if(legal(i, j) == false)return false;
        
        visited[i][j] = true;
        spiral[i][j] = val++;
        
        //NOTE: keep previous direction. if true, don't explore other directions
        if( dfs(i+pre_dir.first, j+pre_dir.second, pre_dir, val) == true ) return true;
        
        //NOTE: only 1 directions work
        pre_dir = {1,0};
        dfs(i+pre_dir.first, j+pre_dir.second, pre_dir, val);
        pre_dir = {-1,0};
        dfs(i+pre_dir.first, j+pre_dir.second, pre_dir, val);
        pre_dir = {0,1};
        dfs(i+pre_dir.first, j+pre_dir.second, pre_dir, val);
        pre_dir = {0,-1};
        dfs(i+pre_dir.first, j+pre_dir.second, pre_dir, val);
        return true;//NOTE: explored all directions, don't explore more
    }
public:
    vector<vector<int>> generateMatrix(int n) {
        this->n = n;
        visited = vector<vector<bool>>(n, vector<bool>(n, false));
        spiral = vector<vector<int>>(n, vector<int>(n));
        dfs(0, 0, pair<int,int>({0,1}) );
        return spiral;
    }
};
