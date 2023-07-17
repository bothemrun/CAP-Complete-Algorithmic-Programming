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
    int n;
    vector<vector<int>> al;
    vector<int> indegree;

    void find_cycle_connected_undirected_indegree1(vector<int>& cycle){

        vector<bool> cyclic(n, true);

        queue<int> q;
        //NOTE: start with indegree == 1, no isolated nodes.
        for(int i=0;i<n;i++)if( indegree[i] == 1 )
            q.push(i);
        

        while(q.size()){
            int lsize = q.size();
            for(int l=0;l<lsize;l++){
                int u = q.front();
                q.pop();

                cyclic[u] = false;


                for(const int& v: al[u])if( --indegree[v] == 1 )
                    q.push(v);
            }
        }

        for(int i=0;i<n;i++)if(cyclic[i] == true)
            cycle.push_back(i);
    }

    vector<int> distanceToCycle(int n, vector<vector<int>>& edges) {
        //1. build graph
        this->n = n;

        al.resize(n);
        indegree.resize(n, 0);
        for(const vector<int>& e: edges){
            al[e[0]].push_back(e[1]);
            al[e[1]].push_back(e[0]);

            indegree[e[0]]++;
            indegree[e[1]]++;
        }

        //2. find nodes in the cycle of a connected undirected graph
        //by a modified onion peeling topological sort with indegree==1
        vector<int> cycle;
        find_cycle_connected_undirected_indegree1(cycle);

        // 3. vanilla bfs
        queue<int> q;
        vector<int> dist(n);
        vector<bool> inq(n, false);
        
        for(const int& c: cycle){
            q.push(c);
            dist[c] = 0;
            inq[c] = true;
        }

        int level = 1;
        while(q.size()){
            int lsize = q.size();
            for(int l=0;l<lsize;l++){
                int u = q.front();
                q.pop();

                for(const int& v: al[u])if(inq[v] == false){
                    q.push(v);
                    inq[v] = true;

                    dist[v] = level;
                }
            }

            level++;
        }

        return dist;
    }
};
