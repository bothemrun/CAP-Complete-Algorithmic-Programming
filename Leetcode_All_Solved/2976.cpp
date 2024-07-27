//m0
//preprocessing: all pairs shortest path:
//floyd-warshall in O(V^3)
//dijkstra in V * O(ElogV) = O(V^3logV)
#define tii tuple<int,int>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    const int n = 26;
    vector<vector<tii>> al;

    inline void decrease_key(set<tii>& qset, int v, int old_dist, int new_dist){
        //ok if not found
        qset.erase(tii(old_dist, v));
        qset.insert(tii(new_dist, v));
    }

    inline void dijkstra(vector<int>& dist, const int src){
        dist.resize(n, INT_MAX);
        set<tii> qset;
        vector<bool> finalized(n, false);

        qset.insert(tii(0, src));
        dist[src] = 0;

        while(qset.size()){
            //can't use reference const auto&
            auto [u_dist, u] = *qset.begin();
            qset.erase(qset.begin());

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
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        al.resize(n);
        for(int j=0;j<(int)cost.size();j++){
            al[ original[j]-'a' ].push_back(tii( cost[j], changed[j]-'a' ));
        }

        vector<vector<int>> dist(n);
        for(int src=0;src<n;src++){
            dijkstra(dist[src], src);
        }


        long long ans = 0;
        for(int i=0;i<(int)source.size();i++){
            if( dist[ source[i]-'a' ][ target[i]-'a' ] == INT_MAX){
                return (-1);
            }

            ans += dist[ source[i]-'a' ][ target[i]-'a' ];
        }
        return ans;
    }
};
