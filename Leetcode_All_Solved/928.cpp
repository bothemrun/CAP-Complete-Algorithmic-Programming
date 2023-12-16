//O(n^2)

#include<algorithm>
#include<assert.h>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int n;
    vector<vector<int>> al;

    int dfs(vector<bool>& visited, const int& u){
        if(visited[u]) return 0;
        visited[u] = true;

        int cnt = 1;
        for(const int& v: al[u])
            cnt += dfs(visited, v);
        return cnt;
    }

    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        n = graph.size();

        al.resize(n);
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)if(graph[i][j]){
                al[i].push_back(j);
                al[j].push_back(i);
            }
        
        int min_infect = n + 1;
        int min_infect_i = (-1);
        for(const int& remove: initial){
            vector<bool> visited(n, false);
            visited[remove] = true;

            int infect = 0;
            for(const int& src: initial)if(src != remove)
                infect += dfs(visited, src);

            if(infect < min_infect){
                min_infect = infect;
                min_infect_i = remove;
            }else if(infect == min_infect){
                min_infect_i = min(min_infect_i, remove);
            }
        }

        assert(min_infect_i != (-1));
        return min_infect_i;
    }
};
