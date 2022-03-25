#include<algorithm>
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int min_window = nums.size() + 1;
        int window_sum = 0;
        for(int left=0, right=0;right<nums.size();right++){
            window_sum += nums[right];
            if(window_sum < target)continue;
            
            while(window_sum - nums[left] >= target){
                window_sum -= nums[left++];
            }
            
            min_window = min(min_window, 1+right-left);
        }
        
        if(min_window == nums.size() + 1)return 0;
        return min_window;
    }
};
