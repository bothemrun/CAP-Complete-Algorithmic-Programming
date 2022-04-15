#include<algorithm>
class Solution {
private:
    int n;
    vector<int> dag_start;
    vector<int> state;//NOTE: discovered, in recursion stack, all its outgoing vertices finished
    bool dfs(int u, const vector<vector<int>>& adjlist){
        state[u] = 1;
        for(const int& v:adjlist[u]){
            if(state[v] == 0 && dfs(v, adjlist) == false)return false;
            if(state[v] == 1)return false;
        }
        state[u] = 2;
        dag_start.push_back(u);
        return true;
    }
    inline void topo_sort(const vector<vector<int>>& adjlist){
        state = vector<int>(n, 0);
        for(int i=0;i<n;i++)if(state[i] == 0)
            dfs(i, adjlist);
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        n = graph.size();
        topo_sort(graph);
        sort(dag_start.begin(), dag_start.end());
        return dag_start;
    }
};
