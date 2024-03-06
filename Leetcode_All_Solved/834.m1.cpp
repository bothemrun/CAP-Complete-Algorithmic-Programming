//m1
//rerooting, dp on trees

//1. ans[root] = ans[par] - cnt[child] + (n - cnt[root])
//O(n)

#include<iostream>
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

    vector<int> cnt;
    vector<int> ans;//no overflow

    int postorder_sum1_cnt(const int& root, const int& par=(-1)){
        cnt[root] = 1;
        //no overflow
        int sum = 0;
        for(const int& child: al[root])if(child != par){
            int sum_child = postorder_sum1_cnt(child, root);
            cnt[root] += cnt[child];
            sum += sum_child;
        }

        sum += cnt[root] - 1;

        return sum;
    }

    void preorder_rerooting(const int& root, const int& par){
        ans[root] = ans[par] - cnt[root] + (n - cnt[root]);

        for(const int& child: al[root])if(child != par)
            preorder_rerooting(child, root);
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        this->n = n;
        al.resize(n);
        for(const vector<int>& e: edges){
            al[e[0]].push_back(e[1]);
            al[e[1]].push_back(e[0]);
        }

        cnt.resize(n);
        const int any_root = 0;
        int sum_root = postorder_sum1_cnt(any_root);

        ans.resize(n);
        ans[any_root] = sum_root;

        for(const int& child: al[any_root])
            preorder_rerooting(child, any_root);
        return ans;
    }
};
