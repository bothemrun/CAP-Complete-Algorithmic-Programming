#include<queue>
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //NOTE: DAG. Kahn's algo, deleting arcs, indegree
        int n = numCourses;
        vector<int> indegree(n, 0);
        vector<vector<int>> adjlist(n, vector<int>());
        for(const vector<int>& ab:prerequisites){
            indegree[ab[0]]++;
            adjlist[ab[1]].push_back(ab[0]);
        }
        
        queue<int> q;
        for(int i=0;i<n;i++)if(indegree[i]==0)q.push(i);
        int topo_cnt = 0;
        while(q.size() != 0){
            int u = q.front();
            q.pop();
            topo_cnt++;
            
            for(const int& v:adjlist[u]){
                indegree[v]--;
                if(indegree[v] == 0)q.push(v);
            }
        }
        
        return (topo_cnt == n);
    }
};
