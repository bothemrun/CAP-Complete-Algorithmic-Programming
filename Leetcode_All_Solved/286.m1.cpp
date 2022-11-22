//m1
class Solution {
public:
    int m, n;
    vector<int> dirx = {1, -1, 0, 0};
    vector<int> diry = {0, 0, 1, -1};
    void dist_dfs(vector<vector<int>>& dist, int i, int j, int cur_dist){
        if(!(0<=i && i<m && 0<=j && j<n))return;
        if(dist[i][j] == (-1))return;
        
        if(dist[i][j] == 0){
            //NOTE: not real source now. adjacent sources cause nonstop stack overflow !
            if(cur_dist != 0)return;
            //else dist[i][j] = 0;
        }else{
            if(dist[i][j] <= cur_dist)return;//NOTE: can't improve !!
            else dist[i][j] = cur_dist;   
        }
        
        for(int k=0;k<4;k++)
            dist_dfs(dist, i+dirx[k], j+diry[k], cur_dist + 1);
    }
    void wallsAndGates(vector<vector<int>>& rooms) {
        m = rooms.size();
        n = rooms[0].size();
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)if(rooms[i][j] == 0)
                dist_dfs(rooms, i, j, 0);
    }
};
