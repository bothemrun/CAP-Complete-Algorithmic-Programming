//m0
//do 2 topogical sort: intra-group and inter-group.

#include<queue>
#include<assert.h>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    inline bool topological_dag(const vector<vector<int>>& al, vector<int>& indegree, vector<int>& order){
        queue<int> q;
        for(int i=0;i<indegree.size();i++)if(indegree[i] == 0)
            q.push(i);
        
        int topo_cnt = 0;
        while(q.size()){
            int level_size = q.size();
            for(int l=0;l<level_size;l++){
                int u = q.front();
                q.pop();

                topo_cnt++;

                order.push_back(u);

                for(const int& v: al[u])if(--indegree[v] == 0)
                    q.push(v);
            }
        }

        return topo_cnt == indegree.size();
    }

    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        //assigne group id
        for(int i=0;i<n;i++)if(group[i] == (-1))
            group[i] = m++;

        vector<vector<int>> al_i(n);
        vector<vector<int>> al_g(m);
        vector<int> indegree_i(n, 0);
        vector<int> indegree_g(m, 0);

        for(int v=0;v<n;v++){
            for(const int& u: beforeItems[v]){
                if(group[u] == group[v]){
                    al_i[u].push_back(v);
                    indegree_i[v]++;
                }else{
                    al_g[ group[u] ].push_back( group[v] );
                    indegree_g[ group[v] ]++;
                }
            }
        }

        //topo for groups
        vector<int> order_g;
        if( topological_dag(al_g, indegree_g, order_g) == false) return vector<int>();

        //topo for items
        vector<int> order_i;
        if( topological_dag(al_i, indegree_i, order_i) == false) return vector<int>();

        //NOTE: a sorted list for each group, then merge k sorted list
        vector<vector<int>> order_g2i(m);
        for(const int& i: order_i)
            order_g2i[ group[i] ].push_back(i);
        
        vector<int> order;
        for(const int& g: order_g)
            order.insert(order.end(), order_g2i[g].begin(), order_g2i[g].end());
        return order;
    }
};
