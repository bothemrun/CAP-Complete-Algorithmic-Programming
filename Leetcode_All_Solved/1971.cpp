class Solution {
private:
    vector<vector<int>> adjlist;
    vector<bool> visited;
    bool dfs_has_path(int u, const int& dest){
        if(u == dest)return true;
        if(visited[u])return false;
        
        visited[u] = true;
        for(const int& v:adjlist.at(u))if(dfs_has_path(v, dest))
            return true;
        return false;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        //build adj list
        adjlist.resize(n);
        visited = vector<bool>(n, false);
        for(const vector<int>& e:edges){
            adjlist.at(e[0]).push_back(e[1]);
            adjlist.at(e[1]).push_back(e[0]);
        }
        //
        return dfs_has_path(source, destination);
    }
};
