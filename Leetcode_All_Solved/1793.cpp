//m0
//O(nlogn)
//binary search with prefix / suffix min array

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
    int n;
    int ans;

    inline void binary_search_prefix_min(const vector<int>& nums, const int& k){
        vector<int> suffix_min(k+1 - 1);
        int suffix_min_tmp = nums[k];

        for(int i=k-1;i>=0;i--){
            suffix_min_tmp = min(suffix_min_tmp, nums[i] );

            suffix_min[i] = suffix_min_tmp;
        }


        int prefix_min = nums[k];
        for(int j=k;j<n;j++){
            prefix_min = min(prefix_min, nums[j] );

            int i = lower_bound(suffix_min.begin(), suffix_min.end(), prefix_min) - suffix_min.begin();

            //[i, j] closed interval
            ans = max(
                ans,
                (j - (i-1)) * prefix_min
            );
        }
    }

    int maximumScore(vector<int>& nums, int k) {
        this->n = nums.size();
        ans = nums[k];

        binary_search_prefix_min(nums, k);

        reverse(nums.begin(), nums.end());
        binary_search_prefix_min(nums, (n-1) - k);

        return ans;
    }
};
