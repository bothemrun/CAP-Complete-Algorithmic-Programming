//m2
//rerooting, dp on trees

//1. ans[root] = ans[par] - cnt[child] + (n - cnt[root])
//O(n)
//2. method m1 fills in answers[node], while method m2 fills in answers[child]

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
    vector<int> sod;//no overflow

    int postorder_fixed_cnt(const int& node, const int& par=(-1)){
        int sum = 0;
        cnt[node] = 1;
        for(const int& child: al[node])if(child != par){
            sum += postorder_fixed_cnt(child, node);
            
            cnt[node] += cnt[child];
        }

        sum += cnt[node] - 1;
        return sum;
    }

    void preorder_rerooting(const int& node, const int& par=(-1)){
        for(const int& child: al[node])if(child != par){
            sod[child] = sod[node] - cnt[child] + (n - cnt[child]);

            preorder_rerooting(child, node);
        }
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
        int sum_root = postorder_fixed_cnt(any_root);

        sod.resize(n);
        sod[any_root] = sum_root;

        preorder_rerooting(any_root);
        return sod;
    }
};
