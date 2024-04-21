//O(4n) greedy

#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<vector<int>> al;
    vector<int> ans;
    vector<bool> visited;

    void dfs(int node){
        if(visited[node] == true) return;
        visited[node] = true;

        vector<bool> color(5, false);
        for(const int& child: al[node])if(visited[child] == true)
            color[ ans[child] ] = true;
        
        for(int i=1;i<=4;i++)if(color[i] == false)
            ans[node] = i;
        
        for(const int& child: al[node])
            dfs(child);
    }

    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        al.resize(n);
        for(const vector<int>& e: paths){
            al[e[0]-1].push_back(e[1]-1);
            al[e[1]-1].push_back(e[0]-1);
        }

        ans.resize(n);
        visited.resize(n, false);
        
        for(int i=0;i<n;i++) dfs(i);

        return ans;
    }
};
