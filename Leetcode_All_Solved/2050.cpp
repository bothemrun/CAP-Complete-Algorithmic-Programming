//m0
//topological sort by onion peeling / bfs
#define max_n ((int)5e4)
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
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n);
        int indegree[max_n] = {0};
        for(const vector<int>& e: relations){
            adj[e[0] - 1].push_back(e[1] - 1);//to 0-indexed
            indegree[e[1] - 1]++;
        }

        int memo[max_n] = {0};
        int max_finish = 0;
        //topological sort by bfs / onion peeling
        queue<int> q;
        for(int i=0;i<n;i++)if(indegree[i] == 0)
            q.push(i);
        while(q.size()){
            int level_size = q.size();
            for(int k=0;k<level_size;k++){
                int cur = q.front();
                q.pop();

                memo[cur] += time[cur];
                max_finish = max(max_finish, memo[cur] );

                for(const int& nex: adj[cur]){
                    memo[nex] = max(memo[nex], memo[cur] );
                    if(--indegree[nex] == 0)
                        q.push(nex);
                }
            }
        }

        return max_finish;
    }
};
