//overall complexity = vanilla dfs complexity O(E+V)

#include<unordered_set>
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
    vector<bool> visited;

    void dfs(const int& u, unordered_set<int>& component){
        if(visited[u] == true) return;
        visited[u] = true;

        component.insert(u);

        for(const int& v: al[u]) dfs(v, component);
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        al.resize(n);
        for(const vector<int>& e: edges){
            al[e[0]].push_back(e[1]);
            al[e[1]].push_back(e[0]);
        }


        int complete_cnt = 0;
        visited.resize(n, false);
        for(int i=0;i<n;i++)if(visited[i] == false){
            unordered_set<int> component;
            dfs(i, component);

            bool complete = true;
            for(const int& u: component){
                if(al[u].size() != (int)component.size() - 1){
                    complete = false;
                    break;
                }
            }

            if(complete) complete_cnt++;
        }

        return complete_cnt;
    }
};
