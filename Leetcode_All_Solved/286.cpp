class Solution {
public:
    int m, n;
    void dfs(vector<vector<int>>& rooms, int i, int j, int dist){
        if(!(0<=i && i<m && 0<=j && j<n))return;
        if(rooms[i][j] == (-1))return;
        
        if(dist != 0 && rooms[i][j] <= dist)return;
        if(dist != 0)rooms[i][j] = dist;
        dfs(rooms, i+1, j, dist+1);
        dfs(rooms, i-1, j, dist+1);
        dfs(rooms, i, j+1, dist+1);
        dfs(rooms, i, j-1, dist+1);
    }
    void wallsAndGates(vector<vector<int>>& rooms) {
        m = rooms.size();
        n = rooms[0].size();
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)if(rooms[i][j] == 0)
                dfs(rooms, i, j, 0);
    }
};
