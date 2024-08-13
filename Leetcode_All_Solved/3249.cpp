//O(n)
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int n;
    vector<vector<int>> al;
    int ans = 0;
    int postorder(int node, int par=(-1)){
        int cnt = 1;

        bool first = true;
        int first_child_cnt;
        bool good = true;

        for(const int& child: al[node])if(child != par){
            int child_cnt = postorder(child, node);
            cnt += child_cnt;

            if(first == true){
                first_child_cnt = child_cnt;
                first = false;
            }else{
                if(first_child_cnt != child_cnt) good = false;
            }
        }

        ans += good;
        return cnt;
    }

    int countGoodNodes(vector<vector<int>>& edges) {
        n = (int)edges.size() + 1;
        al.resize(n);
        for(const vector<int>& e: edges){
            al[e[0]].push_back(e[1]);
            al[e[1]].push_back(e[0]);
        }
        const int root = 0;
        postorder(root);
        return ans;
    }
};
