//O(n)
#include<algorithm>
#include<limits.h>

class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();

        int min_sum2 = INT_MAX;
        int suffix_min = nums.back();
        for(int i=n-2;i>=1;i--){
            min_sum2 = min(
                min_sum2,
                suffix_min + nums[i]
            );

            suffix_min = min(suffix_min, nums[i]);
        }

        return min_sum2 + nums.front();
    }
};
