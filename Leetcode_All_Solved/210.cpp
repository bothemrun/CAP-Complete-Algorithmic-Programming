#include<queue>
class Solution {
private:
    int n;
    vector<vector<int>> adjlist;
    inline void make_graph(const vector<vector<int>>& edges){
        adjlist = vector<vector<int>>(n, vector<int>());
        for(const vector<int>& ab:edges)adjlist[ ab[1] ].push_back(ab[0]);
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //NOTE: DAG topological sort. by Kahn's Algo. deleting arcs, indegree
        n = numCourses;
        make_graph(prerequisites);
        
        vector<int> topo;
        vector<int> indegree(n, 0);
        for(const vector<int>& ab:prerequisites)indegree[ ab[0] ]++;
        queue<int> q;
        for(int i=0;i<n;i++)if(indegree[i] == 0)q.push(i);
        while(q.size() != 0){
            int u = q.front();
            q.pop();
            topo.push_back(u);
            
            for(const int& v:adjlist[u]){
                indegree[v]--;
                if(indegree[v] == 0)q.push(v);
            }
        }
        
        if(topo.size() != n)return vector<int>();
        else return topo;
    }
};
