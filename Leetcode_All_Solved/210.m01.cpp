//m01
//topo sort by bfs / onion peeling
#include<queue>

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        for(const vector<int>& e: prerequisites){
            adj[e[1]].push_back(e[0]);
            indegree[e[0]]++;
        }
        
        //topo sort
        vector<int> topo;
        int topo_cnt = 0;

        queue<int> q;
        vector<bool> inq(n, false);
        
        for(int i=0;i<n;i++)if(indegree[i]==0){
            q.push(i);
            inq[i] = true;
        }

        while(q.size()){
            int level_size = q.size();
            for(int l=0;l<level_size;l++){
                int u = q.front();
                q.pop();

                topo_cnt++;
                topo.push_back(u);

                for(const int& v: adj[u])if(inq[v] == false){
                    if(--indegree[v]==0){
                        q.push(v);
                        inq[v] = true;
                    }
                }
            }
        }

        return (topo_cnt==n)? topo:vector<int>();
    }
};
