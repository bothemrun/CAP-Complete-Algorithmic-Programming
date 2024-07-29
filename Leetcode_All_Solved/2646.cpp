//m0
//O(all trips' dfs + dp) = O(|trips| * n) + O(n) = O(5e3)
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<vector<int>> al;
    vector<int> cnt;
    vector<vector<int>> memo;
    const int notyet = (-1);

    bool on_target_path_postorder(const int& target, int node, int par=(-1)){
        bool target_path = node == target;

        for(const int& child: al[node])if(child != par){
            target_path |= on_target_path_postorder(target, child, node);
        }

        cnt[node] += target_path;
        return target_path;
    }

    int choose_skip(const vector<int>& price, int node, bool choose, int par=(-1)){
        if(memo[node][choose] != notyet) return memo[node][choose];

        //choose or skip children
        int ret = cnt[node] * price[node];
        if(choose==true) ret /= 2;

        for(const int& child: al[node])if(child != par){
            ret += (choose==true)?
                choose_skip(price, child, false, node):
                min(
                    choose_skip(price, child, false, node),
                    choose_skip(price, child, true, node)
                );
        }
        return memo[node][choose] = ret;
    }

    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {

        al.resize(n);
        for(const vector<int>& e: edges){
            al[e[0]].push_back(e[1]);
            al[e[1]].push_back(e[0]);
        }

        cnt.resize(n, 0);
        for(const vector<int>& t: trips){
            on_target_path_postorder(t[1], t[0]);
        }

        memo.resize(n, vector<int>(2, notyet));
        const int anyroot = 0;
        return min(
            choose_skip(price, anyroot, false),
            choose_skip(price, anyroot, true)
        );
    }
};
