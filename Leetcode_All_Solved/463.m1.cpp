//m1
//with BFS
#include<queue>
class Solution {
private:
    int m, n;
    vector<vector<bool>> visited_inqueue_land;
    int perimeter = 0;
    
    inline  void bfs_help(const vector<vector<int>>& grid, int i, int j, queue<vector<int>>& q){
        if(!(0<=i && i<m && 0<=j && j<n)){
            perimeter++;
            return;
        }
        if(grid[i][j] == 0){
            perimeter++;
            return;
        }
        
        //now it's land
        if(visited_inqueue_land[i][j])return;
        else q.push(vector<int>({i,j}));
        visited_inqueue_land[i][j] = true;//NOTE: also for already in queue, or repeatedly in queue
    }
    inline void bfs(const vector<vector<int>>& grid, int src_i, int src_j){
        queue<vector<int>> q;
        q.push(vector<int>({src_i, src_j}));
        while(q.size() != 0){
            vector<int> ij = q.front();
            q.pop();
            int i = ij[0], j = ij[1];
            visited_inqueue_land[i][j] = true;
            
            bfs_help(grid, i+1, j, q);
            bfs_help(grid, i-1, j, q);
            bfs_help(grid, i, j+1, q);
            bfs_help(grid, i, j-1, q);
        }
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        visited_inqueue_land = vector<vector<bool>>(m, vector<bool>(n, false));
        for(int i=0;i<m;i++)for(int j=0;j<n;j++)if(grid[i][j]){
            bfs(grid, i, j);//NOTE: must only once
            return perimeter;
        }
        return (-100);//not here
    }
};
