//[A] dimension reduction
//1. 1D problem: just sort.

//[B] decouple
//1. decouple x & y into 2 groups of movements.

//[C] how to prevent the same cell collision?
//1. in any decoupled x/y movement group, move the outer coordinates first.

//O(nlogn)

static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int minMoves(vector<vector<int>>& rooks) {
        vector<int> decoupled_x, decoupled_y;
        for(const vector<int>& r: rooks){
            decoupled_x.push_back(r[0]);
            decoupled_y.push_back(r[1]);
        }
        sort(decoupled_x.begin(), decoupled_x.end());
        sort(decoupled_y.begin(), decoupled_y.end());

        int n = rooks.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            ans += abs(i - decoupled_x[i]) + abs(i - decoupled_y[i]);
        }
        return ans;
    }
};
