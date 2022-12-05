#include<stdlib.h>
#include<algorithm>
struct minmax{
    int min;
    int max;
};
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        vector<struct minmax> dp_ending(n);
        struct minmax minmax0 = {nums[0], nums[0]};
        dp_ending[0] = minmax0;
        
        for(int i=1;i<n;i++){
            int min3 = min(nums[i], min(nums[i]+dp_ending[i-1].min, nums[i]+dp_ending[i-1].max) );
            int max3 = max(nums[i], max(nums[i]+dp_ending[i-1].min, nums[i]+dp_ending[i-1].max));
            struct minmax minmax_i = {min3, max3};
            dp_ending[i] = minmax_i;
        }
        
        int abs_max = (-1);
        for(struct minmax& mm: dp_ending){
            abs_max = max(abs_max, max( abs(mm.max), abs(mm.min) ) );
        }
        return abs_max;
    }
};
