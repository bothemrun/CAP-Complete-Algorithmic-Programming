//O(n) dp
//1. current state only related to its previous position / state
#define notyet (-1)

#include<limits.h>
#include<assert.h>
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
    vector<vector<int>> memo;
    int only_prev_related(const vector<int>& nums1, const vector<int>& nums2, const int& i, bool swapping){
        if(i==0) return swapping;

        if(memo[i][swapping] != notyet) return memo[i][swapping];

        int cur1 = nums1[i];
        int cur2 = nums2[i];
        if(swapping) swap(cur1, cur2);

        assert(i-1 >= 0);
        int pre1 = nums1[i-1];
        int pre2 = nums2[i-1];

        int ret = INT_MAX;
        if(pre1 < cur1 && pre2 < cur2)
            ret = min(
                ret,
                only_prev_related(nums1, nums2, i-1, false)
            );
        if(pre2 < cur1 && pre1 < cur2)
            ret = min(
                ret,
                only_prev_related(nums1, nums2, i-1, true)
            );
        assert(ret != INT_MAX);
        
        return memo[i][swapping] = swapping + ret;
    }

    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        memo.resize(n, vector<int>(2, notyet));

        return min(
            only_prev_related(nums1, nums2, n-1, true),
            only_prev_related(nums1, nums2, n-1, false)
        );
    }
};
