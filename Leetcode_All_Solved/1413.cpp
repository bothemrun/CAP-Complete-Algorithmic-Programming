#include<algorithm>
class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int prefix_sum = nums[0];
        int min_prefix_sum = nums[0];
        for(int i=1;i<nums.size();i++){
            prefix_sum += nums[i];
            min_prefix_sum = min(min_prefix_sum, prefix_sum);
        }
        
        if(min_prefix_sum >= 1)return 1;
        else return 1 - min_prefix_sum;
    }
};
