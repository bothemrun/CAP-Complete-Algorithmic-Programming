//m1
//m1 is much better. use the original max sum subarray problem
#include<algorithm>
struct minmax{
    int min;
    int max;
};
bool cmp_fn(const struct minmax& a, const struct minmax& b){
    return a.max < b.max;
}
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<struct minmax> dp_ending(n);
        struct minmax minmax0 = {nums[0], nums[0]};
        dp_ending[0] = minmax0;
        
        for(int i=1;i<n;i++){
            int min3 = min(nums[i], min(nums[i]*dp_ending[i-1].min, nums[i]*dp_ending[i-1].max) );
            int max3 = max(nums[i], max(nums[i]*dp_ending[i-1].min, nums[i]*dp_ending[i-1].max));
            struct minmax minmaxi = {min3, max3};
            dp_ending[i] = minmaxi;
        }
        return max_element(dp_ending.begin(), dp_ending.end(), cmp_fn)->max;
    }
};
