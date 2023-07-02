//NOTE: time >= 10, max_time <= 100, so at most 10 edges for 1 traversal.
//edges connected to each node <= 4.
//so a brute force enumeration / backtracking takes O(4^10) = 1e6, ok.

#include<algorithm>
#include<utility>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio();
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<vector<pair<int,int>>> adj;
    int ans = 0;

    void backtrack(const vector<int>& values, vector<bool>& collected, int collect, int remain, int u){
        if(remain < 0) return;

        bool collected_backtrack = collected[u];
        if(collected[u] == false){
            collected[u] = true;

            collect += values[u];
        }


        if(u == 0) ans = max(ans, collect);


        for(const auto& [v, time]: adj[u])
            backtrack(values, collected, collect, remain - time, v);
        
        //NOTE: backtrack to its "original", not "false"
        collected[u] = collected_backtrack;
    }

    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {

        int n = values.size();
        adj.resize(n);
        for(const vector<int>& e: edges){
            adj[e[0]].push_back(pair<int,int>(e[1], e[2]));
            adj[e[1]].push_back(pair<int,int>(e[0], e[2]));
        }

        
        vector<bool> collected(n, false);
        backtrack(values, collected, 0, maxTime, 0);
        return ans;
    }
};
