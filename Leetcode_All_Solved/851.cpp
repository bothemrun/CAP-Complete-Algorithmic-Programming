//O(n) topological sort

#include<queue>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();

        vector<vector<int>> al(n);
        vector<int> indegree(n, 0);
        for(const vector<int>& e: richer){
            al[e[0]].push_back(e[1]);

            indegree[e[1]]++;
        }


        vector<int> ans(n);
        for(int i=0;i<n;i++) ans[i] = i;

        queue<int> q;
        for(int i=0;i<n;i++)if(indegree[i] == 0)
            q.push(i);


        while(q.size()){
            int lsize = q.size();
            for(int l=0;l<lsize;l++){
                int u = q.front();
                q.pop();

                //ans[u] already finished

                for(const int& v: al[u]){
                    if(--indegree[v] == 0)
                        q.push(v);
                    
                    if(quiet[ans[v]] > quiet[ans[u]]){
                        ans[v] = ans[u];
                    }
                }
            }
        }

        return ans;
    }
};
