//m2
//Dijkstra's with set implementation
//O(ElogV) = O(times.length * logn)

#define tii tuple<int,int>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    inline void decrease_key(set<tii>& qset, int v, int old_dist, int new_dist){
        //ok if not found
        qset.erase(tii(old_dist, v));
        qset.insert(tii(new_dist, v));
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<tii>> al(n);
        for(const vector<int>& e: times){
            al[e[0]-1].push_back(tii( e[2], e[1]-1 ));
        }

        set<tii> qset;
        vector<bool> finalized(n, false);
        vector<int> dist(n, INT_MAX);

        const int src = k-1;
        qset.insert(tii(0, src));
        dist[src] = 0;

        while(qset.size()){
            //can't use reference: const auto&
            auto [u_dist, u] = *qset.begin();
            qset.erase( qset.begin() );

            finalized[u] = true;


            for(const auto& [w, v]: al[u])if(finalized[v] == false){
                if(dist[v] > w + dist[u]){
                    //relax
                    int old_dist = dist[v];
                    dist[v] = w + dist[u];

                    decrease_key(qset, v, old_dist, dist[v]);
                }
            }
        }

        int delay = 0;
        for(const int& d: dist){
            if(d == INT_MAX) return (-1);

            delay = max(delay, d);
        }
        return delay;
    }
};
