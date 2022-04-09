#include<unordered_set>
class Solution {
private:
    int right_dir = 0;
    void dfs(const vector<vector<int>>& adjlist, const vector<unordered_set<int>>& adjmat, vector<bool>& visited, int u=0, int pre=(-1)){
        if(visited[u])return;
        
        //NOTE: successfully visited
        visited[u] = true;
        if(pre != (-1) && adjmat[pre].find(u) == adjmat[pre].end())right_dir++;
        
        for(const int& v:adjlist[u])
            dfs(adjlist, adjmat, visited, v, u);
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adjlist(n, vector<int>());//NOTE: bi-direction, hypothetical
        vector<unordered_set<int>> adjmat(n, unordered_set<int>());//NOTE: directional, real, old
        for(const vector<int>& e:connections){
            adjmat[e[0]].insert(e[1]);
            
            adjlist[e[0]].push_back(e[1]);
            adjlist[e[1]].push_back(e[0]);
        }
        vector<bool> visited(n, false);
        
        dfs(adjlist, adjmat, visited);
        return (n-1) - right_dir;
    }
};
