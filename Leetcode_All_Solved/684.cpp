class Solution {
private:
    int n;
    bool dfs_acyclic(const vector<vector<int>>& adjlist, vector<bool>& visited, int u=1, int pre=(-1)){
        if(visited.at(u))return false;
        visited.at(u) = true;
        for(const int& v:adjlist.at(u))if(v != pre)
            if(dfs_acyclic(adjlist, visited, v, u) == false)return false;
        return true;
    }
    bool connected(const vector<bool>& visited){
        //NOTE: 1-based for(bool b:visited)if(b == false)return false;
        for(int i=1;i<visited.size();i++)if(visited[i] == false)return false;
        return true;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        n = edges.size();
        for(int ex=n-1;ex>=0;ex--){
            //build graph
            vector<vector<int>> adjlist(n+1, vector<int>());
            for(int i=0;i<n;i++)if(i != ex){
                adjlist.at( edges[i][0] ).push_back( edges[i][1] );
                adjlist.at( edges[i][1] ).push_back( edges[i][0] );
            }
            vector<bool> visited(n+1, false);
            //
            if(dfs_acyclic(adjlist, visited) && connected(visited))return edges[ex];
        }
        return vector<int>({-3,-3});//not here
    }
};
