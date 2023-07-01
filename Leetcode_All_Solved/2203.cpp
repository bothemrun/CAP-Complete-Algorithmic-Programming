//Dijkstra by set for priority queue
//https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-set-in-stl/

//NOTE: Dijkstra (without the visited marks) works with multi-graph.
//https://stackoverflow.com/questions/13575715/multigraph-and-cheapest-path

#define p pair<long long, int>
#include<set>
#include<algorithm>
#include<utility>
#include<limits.h>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<vector< p >> norm;
    vector<vector< p >> rev;

    inline void Dijkstra(const vector<vector< p >>& adj, const int& src, vector<long long>& dist){
        //NOTE: also handles multi-graph.

        dist.resize(adj.size(), LLONG_MAX);
        set< p > set_pq;

        set_pq.insert( p(0, src) );
        dist[src] = 0;

        while(set_pq.size()){
            auto [d, u] = *set_pq.begin();
            set_pq.erase( set_pq.begin() );

            for(const auto& [weight, v]: adj[u]){

                if(dist[u] + weight < dist[v]){
                    //relax, also for multi-graph
                    set_pq.erase( p(dist[v], v) );
                    dist[v] = dist[u] + weight;
                    set_pq.insert( p(dist[v], v) );
                }
            }
        }
    }

    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        norm.resize(n);
        rev.resize(n);

        //NOTE: also includes the reversed graph.
        for(const vector<int>& e: edges){
            norm[e[0]].push_back( p(e[2], e[1]) );
            rev[e[1]].push_back( p(e[2], e[0]) );
        }


        vector<long long> dist1;
        vector<long long> dist2;
        vector<long long> dist_dest;
        Dijkstra(norm, src1, dist1);
        Dijkstra(norm, src2, dist2);
        Dijkstra(rev, dest, dist_dest);


        //NOTE: enumerate intermediate node in O(n)
        long long min_path = LLONG_MAX;
        for(int mid=0;mid<n;mid++){

            if( dist1[mid] == LLONG_MAX || dist2[mid] == LLONG_MAX || dist_dest[mid] == LLONG_MAX )
                continue;

            min_path = min(
                min_path,
                dist1[mid] + dist2[mid] + dist_dest[mid]
            );
        }
        
        return (min_path==LLONG_MAX)? (-1):min_path;
    }
};
