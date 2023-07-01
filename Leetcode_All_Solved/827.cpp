//2 pass O(n^2)
#define max_n 500
#include<algorithm>
#include<unordered_map>
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
    bool visited[max_n][max_n] = {0};

    int dfs(vector<vector<int>>& grid, const int& i, const int& j, const int& id){
        if(!(0<=i && i<m && 0<=j && j<n)) return 0;
        if(grid[i][j]==0) return 0;

        if(visited[i][j]) return 0;
        visited[i][j] = true;

        grid[i][j] = id;

        int cnt = 1;
        for(int k=0;k<di.size();k++)
            cnt += dfs(grid, i+di[k], j+dj[k], id);
        return cnt;
    }

    int largestIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid.back().size();

        vector<int> component(2);//id starts from 2
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)if(grid[i][j]==1 && visited[i][j]==false){
                component.push_back(
                    dfs(grid, i, j, component.size())
                );
            }
        
        
        //NOTE: edge cases: (1) all 1. (2) all 0
        //int max_area = 1;
        int max_area = (-1);

        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)if(grid[i][j]==0){
                unordered_map<int,int> component2area;
                for(int k=0;k<di.size();k++){
                    int x = i+di[k];
                    int y = j+dj[k];
                    if(!(0<=x && x<m && 0<=y && y<n)) continue;
                    component2area[ grid[x][y] ] = component[ grid[x][y] ];
                }

                //pitfall: self
                int area = 1;
                for(const auto& [key,val]: component2area) area += val;

                max_area = max(max_area, area);
            }

        //NOTE: edge cases: (1) all 1. (2) all 0
        if(max_area == (-1))//all 1 or all 0
            return (grid[0][0]==0)? 1: m*n;

        return max_area;
    }
};
