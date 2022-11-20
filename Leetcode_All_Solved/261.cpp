#include<unordered_set>
class Solution {
public:
    bool dfs(int node, const vector<vector<int>>& adjlist, unordered_set<int>& visited, int parent){
        if(visited.count(node) != 0)return false;
        visited.insert(node);
        
        for(int child: adjlist[node])if(child != parent){
            if(dfs(child, adjlist, visited, node) == false)return false;
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjlist(n, vector<int>());
        for(vector<int>& edge: edges){
            adjlist[edge[0]].push_back(edge[1]);
            adjlist[edge[1]].push_back(edge[0]);
        }
        
        unordered_set<int> visited;
        if(dfs(0, adjlist, visited, (-1)) == false)return false;
        if(visited.size() != n)return false;
        return true;
    }
};
