//m1
//onion peeling / kahn's topological sort with outdegree == 0.
//or topo sort on the reverse graph.

//although not DAG, ok

#include<algorithm>
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
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        //1. reverse graph
        vector<vector<int>> rev_al(n);
        //outdegree of the non-reverse graph
        vector<int> outdegree(n, 0);
        for(int from=0;from<n;from++)
            for(const int& to: graph[from]){
                rev_al[to].push_back(from);

                outdegree[from]++;
            }
        

        vector<int> safe;
        //2. topo sort on non-DAG
        queue<int> q;
        for(int i=0;i<n;i++)if(outdegree[i] == 0)
            q.push(i);
        
        while(q.size()){
            int lsize = q.size();
            for(int l=0;l<lsize;l++){
                int v = q.front();
                q.pop();

                safe.push_back(v);

                for(const int& u: rev_al[v])if( --outdegree[u] == 0 )
                    q.push(u);
            }
        }


        sort(safe.begin(), safe.end());
        return safe;
    }
};
