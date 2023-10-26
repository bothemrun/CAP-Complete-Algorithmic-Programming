//more general: 2127. Maximum Employees to Be Invited to a Meeting

//Thinking Process:

//[A] Anaylize the Cycle
//1. a cycle's edges must all have the same direcitons
//, since at most 1 outgoing edge.
//2. then topological sort can find the cycles, and the cycles are valid real cycles.

#define no_al (-1)
#include<queue>
#include<algorithm>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<bool> visited4cycle;

    int dfs(const vector<int>& al, const int& u){
        if(visited4cycle[u] == true) return 0;
        visited4cycle[u] = true;

        if(al[u] != no_al) return 1 + dfs(al, al[u]);
        else return 1;
    }

    int longestCycle(vector<int>& edges) {
        vector<int>& al = edges;
        int n = al.size();

        queue<int> q;
        vector<int> indegree(n, 0);
        for(int i=0;i<n;i++)if(al[i] != no_al)
            indegree[al[i]]++;
        
        for(int i=0;i<n;i++)if(indegree[i] == 0)
            q.push(i);
        
        visited4cycle.resize(n, false);
        
        while(q.size()){
            int lsize = q.size();
            for(int l=0;l<lsize;l++){
                int u = q.front();
                q.pop();

                visited4cycle[u] = true;

                int v = al[u];
                if(v == no_al) continue;

                if(--indegree[v] == 0)
                    q.push(v);
            }
        }


        int max_cycle = (-1);
        for(int u=0;u<n;u++)if(visited4cycle[u] == false){
            max_cycle = max(
                max_cycle,
                dfs(al, u)
            );
        }

        return max_cycle;
    }
};
