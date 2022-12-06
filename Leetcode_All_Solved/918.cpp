#include<algorithm>
class Solution {
public:
    int n;
    int maxSubarraySum(const vector<int>& nums){
        vector<long long> dp_ending(n);
        dp_ending[0] = nums[0];
        for(int i=1;i<n;i++)
            dp_ending[i] = max((long long)nums[i], (long long)nums[i] + dp_ending[i-1]);
        return *max_element(dp_ending.begin(), dp_ending.end());
    }
    int maxSubarraySumCross(const vector<int>& nums){
        vector<long long> max_prefix_sum(n);
        max_prefix_sum[0] = max(0, nums[0]);
        long long prefix_sum = nums[0];
        for(int i=1;i<n;i++){
            prefix_sum += nums[i];
            max_prefix_sum[i] = max(prefix_sum, max_prefix_sum[i-1]);
        }

        long long suffix_sum = 0;
        long long max_cross = nums[0];
        for(int i=n-1;i>=1;i--){
            suffix_sum += nums[i];
            max_cross = max(max_cross, suffix_sum + max_prefix_sum[i-1]);
        }
        //skip whole sum, already done in the normal case
        return max_cross;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        n = nums.size();
        int max_sub = maxSubarraySum(nums);
        int max_cross = maxSubarraySumCross(nums);
        return max(max_sub, max_cross);
    }
};
