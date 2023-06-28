//m2
//Dijkstra using sets.
//https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-set-in-stl/

#define p(a, b) ( pair<double,int>(a, b) )
#define min_prob (-1.0)
#include<set>
#include<utility>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<double, int>>> adj(n);
        int m = edges.size();
        for(int i=0;i<m;i++){
            const vector<int>& e = edges[i];
            adj[e[0]].push_back(p(succProb[i], e[1]));
            adj[e[1]].push_back(p(succProb[i], e[0]));
        }

        vector<double> dist(n, min_prob);
        auto cmp_fn = [](const pair<double,int>& a, const pair<double,int>& b){
            //NOTE: return a.first > b.first;
            //NOTE: comparator also for determining uniqueness.
            if(a.first != b.first) return a.first > b.first;
            else return a.second < b.second;
        };
        set<pair<double, int>, decltype(cmp_fn)> set_pq(cmp_fn);

        set_pq.insert(p(1.0, start));
        dist[start] = 1.0;
        
        while(set_pq.size()){
            auto [u_dist, u] = *set_pq.begin();
            set_pq.erase(set_pq.begin());

            if(u == end) return dist[u];

            for(const auto& [weight, v]: adj[u]){
                if(dist[u] * weight > dist[v] ){
                    set_pq.erase(p(weight, v));
                    dist[v] = dist[u] * weight;
                    set_pq.insert(p(dist[v], v));
                }
            }
        }

        return 0.0;
    }
};
