//O(nlogn)
#define tll tuple<long long, long long>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int k;
    vector<vector<tll>> al;

    tll connect_parent_or_not(const int node, const int parent=(-1)){
        long long sum = 0;
        vector<long long> connect_delta;
        for(const auto& [child, weight]: al[node])if(child != parent){
            const auto [not_connect, connect] = connect_parent_or_not(child, node);
            sum += not_connect;

            const long long delta = connect + weight - not_connect;
            if(delta > 0) connect_delta.push_back(delta);
        }

        sort(connect_delta.begin(), connect_delta.end(), [](const int& a, const int& b){
            return a>b;
        });

        //connect k-1
        for(int i=0;i<min(k-1, (int)connect_delta.size());i++){
            sum += connect_delta.at(i);
        }

        //connect k
        long long connect_k_sum = sum + ( (k <= (int)connect_delta.size())? connect_delta.at(k-1):0 );

        return {connect_k_sum, sum};
    }

    long long maximizeSumOfWeights(vector<vector<int>>& edges, int k) {
        this->k = k;
        int n = (int)edges.size() + 1;
        al.resize(n);
        for(const vector<int>& e: edges){
            al[e[0]].push_back(tll( e[1], e[2] ));
            al[e[1]].push_back(tll( e[0], e[2] ));
        }

        const int root = 0;
        auto [not_connect, connect] = connect_parent_or_not(root);
        return not_connect;
    }
};
