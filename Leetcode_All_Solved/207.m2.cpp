//m2
#define max_n 2000
#include<queue>

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        int indegree[max_n] = {0};//fast init by array
        vector<vector<int>> adj(n);
        for(const vector<int>& e: prerequisites){
            adj[e[1]].push_back(e[0]);
            indegree[e[0]]++;
        }

        queue<int> q;
        bool inq[max_n] = {0};
        for(int i=0;i<n;i++)if(indegree[i]==0){
            q.push(i);
            inq[i] = true;
        }

        int topo_cnt = 0;
        while(q.size()){
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

        return topo_cnt == n;
    }
};
