//minimum spanning tree by Kruskal's, 
//with union find by rank with path compression in amortized O(1)

#define ROOT (-1)
#include<algorithm>
#include<assert.h>

class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> visited;

    vector<int> dsu;
    vector<int> rank;
    inline void make_set(const int& size){
        dsu.resize(size, ROOT);
        rank.resize(size, 1);
    }
    int set_find(const int& a){
        if(dsu[a] == ROOT) return a;
        return dsu[a] = set_find(dsu[a]);
    }
    inline void set_join(int a, int b){
        a = set_find(a);
        b = set_find(b);
        if(a == b) return;

        if(rank[a] < rank[b]) dsu[a] = b;
        else if(rank[a] > rank[b]) dsu[b] = a;
        else{
            dsu[a] = b;
            rank[b]++;
        }
    }

    void dfs(const int& u){
        if(visited[u]) return;
        visited[u] = true;

        for(const int& v: adj[u])
            dfs(v);
    }
    bool dfs_connected(int n){
        dfs(0);
        for(int i=0;i<n;i++)if(visited[i]==false) return false;
        return true;
    }

    int minimumCost(int n, vector<vector<int>>& connections) {
        //check connectedness
        adj.resize(n);
        visited.resize(n, false);
        for(const vector<int>& e: connections){
            //to 0-indexed
            adj[ e[0]-1 ].push_back( e[1]-1 );
            adj[ e[1]-1 ].push_back( e[0]-1 );
        }
        if( dfs_connected(n) == false) return (-1);


        //minimum spanning tree by kruskal
        make_set(n);

        auto cmp_fn = [](const vector<int>& a, const vector<int>& b){
            return a[2] < b[2];
        };
        sort(connections.begin(), connections.end(), cmp_fn);

        int node_cnt = 0;
        int cost = 0;
        for(const vector<int>& e: connections){
            int u = e[0]-1, v = e[1]-1;//0-indexed
            if(set_find(u) == set_find(v)) continue;

            set_join(u, v);
            cost += e[2];
            if(++node_cnt == n-1) break;
        }
        assert(node_cnt==n-1);

        return cost;
    }
};
