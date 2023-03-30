//m0
//find connected components by dfs
#include<algorithm>
class Solution {
public:
    void dfs(const vector<vector<int>>& adjl, vector<bool>& visited, const int& i, vector<int>& component){
        if(visited[i])return;
        visited[i] = true;
        component.push_back(i);

        for(const int& v: adjl[i])
            dfs(adjl, visited, v, component);
    }

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        //connected components
        int n = s.size();
        vector<vector<int>> adjl(n);
        for(const vector<int>& e: pairs){
            adjl[e[0]].push_back(e[1]);
            adjl[e[1]].push_back(e[0]);
        }

        vector<vector<int>> connected_component;
        vector<bool> visited(n, false);
        for(int i=0;i<n;i++)if(visited[i] == false){
            vector<int> component;
            dfs(adjl, visited, i, component);

            connected_component.push_back(component);
        }

        //smallest string
        for(vector<int>& component: connected_component){
            sort(component.begin(), component.end());
            vector<char> component_s;
            for(const int& idx: component)
                component_s.push_back(s[idx]);
            sort(component_s.begin(), component_s.end());

            for(int i=0;i<component.size();i++)
                s[component[i]] = component_s[i];
        }
        return s;
    }
};
