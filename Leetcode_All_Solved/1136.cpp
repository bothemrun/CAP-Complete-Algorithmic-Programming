//m0
//topological sort by onion peeling / bfs
//cycle detection by topo cnt
#include<queue>

class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        for(const vector<int>& e: relations){
            //all to 0-indexed
            adj[e[0] - 1].push_back(e[1] - 1);
            indegree[e[1] - 1]++;
        }

        //topo sort
        queue<int> q;
        vector<bool> inq(n, false);
        
        for(int i=0;i<n;i++)if(indegree[i] == 0){
            q.push(i);
            inq[i] = true;
        }

        int level = 0;
        int topo_cnt = 0;
        while(q.size()){
            int level_size = q.size();
            for(int l=0;l<level_size;l++){
                int u = q.front();
                q.pop();

                topo_cnt++;

                for(const int& v: adj[u])if(inq[v] == false){
                    if(--indegree[v] == 0){
                        q.push(v);
                        inq[v] = true;
                    }
                }
            }

            level++;
        }

        return (topo_cnt==n)? level:(-1);
    }
};
