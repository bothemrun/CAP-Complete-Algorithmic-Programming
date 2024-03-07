//O(n) rerooting, dp on trees
//rerooting: update ans[child] instead of ans[node]

#define tib tuple<int,bool>
#include<tuple>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<vector<tib>> al;

    vector<int> ans;

    int postorder(const int& node, const int& par=(-1)){
        int rev = 0;
        for(const auto& [child, dir]: al[node])if(child != par){
            if(dir==false) rev++;

            rev += postorder(child, node);
        }
        return rev;
    }

    void preorder_rerooting(const int& node, const int& par=(-1)){
        for(const auto& [child, dir]: al[node])if(child != par){
            ans[child] = ans[node] + (
                (dir==true)? 1:(-1)
            );

            preorder_rerooting(child, node);
        }
    }

    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        al.resize(n);
        for(const vector<int>& e: edges){
            al[e[0]].push_back( tib(e[1], true) );
            al[e[1]].push_back( tib(e[0], false) );
        }


        ans.resize(n);
        const int any_root = 0;
        ans[any_root] = postorder(any_root);

        preorder_rerooting(any_root);
        return ans;
    }
};
