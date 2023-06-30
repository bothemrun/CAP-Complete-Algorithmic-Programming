//minimum spanning by kruskal with union find by rank with path compression
//NOTE: add 1 vertual node for water source

#define water_source 0
#define ROOT (-1)
#include<algorithm>
#include<assert.h>

class Solution {
public:
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
        if(a==b) return;

        if(rank[a] < rank[b]) dsu[a] = b;
        else if(rank[a] > rank[b]) dsu[b] = a;
        else{
            dsu[a] = b;
            rank[b]++;
        }
    }
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        //NOTE: add 1 vertual node for water source
        for(int i=1;i<=n;i++)
            pipes.push_back(vector<int>({water_source, i, wells[i-1]}));
        
        //mst by kruskal
        int m = n+1;
        make_set(m);

        auto cmp_fn = [](const vector<int>& a, const vector<int>& b){
            return a[2] < b[2];
        };
        sort(pipes.begin(), pipes.end(), cmp_fn);

        int node_cnt = 1;
        int cost = 0;
        for(const vector<int>& e: pipes){
            int u = e[0], v = e[1];
            if(set_find(u) == set_find(v)) continue;

            set_join(u, v);
            cost += e[2];

            if(++node_cnt == m) break;
        }
        assert(node_cnt == m);

        return cost;
    }
};
