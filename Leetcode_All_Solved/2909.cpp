//O(n) prefix & suffix min array

#include<limits.h>
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
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> suffix_min(n);
        suffix_min.back() = nums.back();
        for(int i=n-1-1;i>=0;i--)
            suffix_min[i] = min( suffix_min[i+1], nums[i] );
        
        int prefix_min = nums.front();
        int min_sum = INT_MAX;
        for(int i=1;i<n-1;i++){
            if(
                prefix_min < nums[i] &&
                nums[i] > suffix_min[i+1]
            ) min_sum = min(
                min_sum,
                prefix_min + nums[i] + suffix_min[i+1]
            );

            prefix_min = min(prefix_min, nums[i]);
        }

        return (min_sum==INT_MAX)? (-1):min_sum;
    }
};
