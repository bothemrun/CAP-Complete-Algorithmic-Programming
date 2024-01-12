//O(n)
#define tu3 tuple<bool, int, int>

#include<tuple>
#include<algorithm>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<vector<int>> al;

    int ans = 0;

    tu3 postorder(const vector<int>& colors, const int& root, const int& pre=(-1)){
        int cnt = 1;
        bool same = true;

        for(const int& child: al[root])if(child != pre){
            //C++17 Structured Binding Declaration
            auto [same_sub, color_sub, cnt_sub] = postorder(colors, child, root);

            if(same_sub == false || color_sub != colors[root])
                same = false;
            
            cnt += cnt_sub;
        }

        if(same == true) ans = max(ans, cnt);

        return {same, colors[root], cnt};
    }

    int maximumSubtreeSize(vector<vector<int>>& edges, vector<int>& colors) {
        int n = colors.size();
        al.resize(n);
        for(const vector<int>& e: edges){
            al[e[0]].push_back(e[1]);
            al[e[1]].push_back(e[0]);
        }

        const int root = 0;
        tu3 ret = postorder(colors, root);
        return ans;
    }
};
