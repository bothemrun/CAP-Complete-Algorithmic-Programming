//m0
//find connectd components by dfs
#include<unordered_map>
class Solution {
public:
    void dfs(const vector<vector<int>>& adjlist, vector<bool>& visited, const int& i, vector<int>& component){
        if(visited[i])return;
        visited[i] = true;
        component.push_back(i);

        for(const int& v: adjlist[i])
            dfs(adjlist, visited, v, component);
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        //find connected components
        int n = source.size();
        vector<vector<int>> adjlist(n);
        for(const vector<int>& e: allowedSwaps){
            adjlist[e[0]].push_back(e[1]);
            adjlist[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);
        vector<vector<int>> connected_component;
        for(int i=0;i<n;i++)if(visited[i] == false){
            vector<int> component;
            dfs(adjlist, visited, i, component);
            connected_component.push_back(component);
        }

        
        //compute hamming distance
        int hamming = 0;
        for(const vector<int>& component: connected_component){
            unordered_map<int,int> val2cnt;
            for(const int& idx: component)
                val2cnt[ source[idx] ]++;

            for(const int& idx: component){
                if(val2cnt.count( target[idx] ) == 0) hamming++;
                else if(--val2cnt[ target[idx] ] == 0)
                    val2cnt.erase(target[idx]);
            }
        }
        return hamming;
    }
};
