//m3
//dfs cycle detection, O(n^2)
//optim from m0 with n*2n, to n*n on the run
#include<assert.h>
class Solution {
public:
    vector<vector<int>> adjlist;

    bool dfs_cyclic(const int& u, vector<bool>& visited, const int& pre=(-1)){
        //NOTE: cyclic
        if(visited[u] == true)return true;
        visited[u] = true;

        for(const int& v: adjlist[u])if(pre != v){
            if(dfs_cyclic(v, visited, u) == true)return true;
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        adjlist = vector<vector<int>>(n);

        for(int i=0;i<n;i++){
            adjlist[edges[i][0]-1].push_back(edges[i][1]-1);
            adjlist[edges[i][1]-1].push_back(edges[i][0]-1);

            vector<bool> visited(n, false);
            if(dfs_cyclic(edges[i][0]-1, visited) == true)return edges[i];
        }

        assert(false);
        return vector<int>({-1, -1});
    }
};
