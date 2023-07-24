//m0
//subtree sum by dfs

#include<algorithm>
#include<limits.h>
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
    vector<int>* nums_ptr;

    int dfs_subtree_sum(const int& root, const int& parent, const int& sum_comp, int& cnt_comp){

        int subtree_sum = nums_ptr->at(root);

        for(const int& child: al[root])if(child != parent){
            subtree_sum += dfs_subtree_sum(child, root, sum_comp, cnt_comp);
        }

        //TODO: pruning / early stopping

        if(subtree_sum == sum_comp){
            cnt_comp++;
            return 0;//NOTE: cut
        }else return subtree_sum;
    }

    inline bool check(const int& sum_comp, const int& target_comp){
        int cnt_comp = 0;//global for dfs
        dfs_subtree_sum(0, (-1), sum_comp, cnt_comp);

        return cnt_comp == target_comp;
    }

    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        nums_ptr = &nums;

        int n = nums.size();
        al.resize(n);
        for(const vector<int>& e: edges){
            al[e[0]].push_back(e[1]);
            al[e[1]].push_back(e[0]);
        }

        int sum_all = 0;
        for(const int& x: nums) sum_all += x;

        int max_comp = INT_MIN;
        //factorize sum_all
        for(int sum_div=1;sum_div*sum_div <= sum_all;sum_div++)if(sum_all % sum_div == 0){

            //TODO: utilized max_comp, pruning / early stopping.

            int sum_comp = sum_div;
            int target_comp = sum_all / sum_comp;

            if(check(sum_comp, target_comp) == true) max_comp = max(max_comp, target_comp);

            swap(sum_comp, target_comp);
            if(check(sum_comp, target_comp) == true) max_comp = max(max_comp, target_comp);
        }

        return max_comp - 1;
    }
};
