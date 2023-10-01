//same tech in: 2440. Create Components With Same Value
#include<assert.h>
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
    int k;
    int component = 0;

    long long postorder_subtree_sum(const vector<int>& values, const int& u, const int& parent=(-1)){
        long long sum = values[u];
        for(const int& v: al[u])if(v != parent){
            sum += postorder_subtree_sum(values, v, u);
        }

        if(sum%k == 0){
            component++;
            return 0;
        }
        return sum;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        this->k = k;

        al.resize(n);
        for(const vector<int>& e: edges){
            al[e[0]].push_back(e[1]);
            al[e[1]].push_back(e[0]);
        }

        const int any_root = 0;
        assert( postorder_subtree_sum(values, any_root) == 0 );
        return component;
    }
};
