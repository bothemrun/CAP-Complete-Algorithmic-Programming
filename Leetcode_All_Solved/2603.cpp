//m0

//1. leaves without coins are not needed. remove them (recursive).
//1.a. by topological sort

//2. now all leaves have coins. remove 2 nodes from the leaves.
//2.a. by toposort for max distance to leaves

//3. answer = 2 * (remaining node's count - 1)
//O(n)

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
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n = coins.size();

        vector<int> indegree(n, 0);

        vector<vector<int>> al(n);
        for(const vector<int>& e: edges){
            al[e[0]].push_back(e[1]);
            al[e[1]].push_back(e[0]);

            indegree[e[0]]++;
            indegree[e[1]]++;
        }

        //1. topo sort
        vector<bool> ever2q(n, false);
        queue<int> q;

        for(int i=0;i<n;i++)if(indegree[i] == 1 && coins[i] == 0){
            q.push(i);
            ever2q[i] = true;
        }

        while(q.size()){
            int qsize = q.size();
            for(int l=0;l<qsize;l++){
                int u = q.front();
                q.pop();

                for(const int& v: al[u])if(ever2q[v] == false){
                    if(--indegree[v] == 1 && coins[v] == 0){
                        q.push(v);
                        ever2q[v] = true;
                    }
                }
            }
        }

        //2. topo sort & distances
        vector<int> dist(n, 0);
        for(int i=0;i<n;i++)if(ever2q[i] == false && indegree[i] == 1){
            q.push(i);
            ever2q[i] = true;
        }

        while(q.size()){
            int qsize = q.size();
            for(int l=0;l<qsize;l++){
                int u = q.front();
                q.pop();

                for(const int& v: al[u])if(ever2q[v] == false){
                    dist[v] = max( dist[v], dist[u] + 1 );

                    if(--indegree[v] == 1){
                        q.push(v);
                        ever2q[v] = true;
                    }
                }
            }
        }

        //3.
        int visit = 0;
        for(int i=0;i<n;i++)if(dist[i] >= 2){
            visit++;
        }

        //edge case: after 2, the max dist from leaf to the central node <= 1
        if(visit-1<0) return 0;
        //edge case: visit==1: just don't need to move on edges
        return 2*(visit - 1);
    }
};
