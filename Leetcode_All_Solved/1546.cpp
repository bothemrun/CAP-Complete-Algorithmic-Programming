#include<unordered_map>
class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        //NOTE: classical Greedy: Activity Selection / Interval Scheduling. ADA greedy slide.
        unordered_map<long long,int> low_prefix_sum2last_idx;
        long long high_prefix_sum = 0;
        int last_used_idx = (-1);
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            high_prefix_sum += nums[i];
            
            //NOTE: greedy priority
            auto it = low_prefix_sum2last_idx.find( high_prefix_sum - target );
            if(it != low_prefix_sum2last_idx.end() && last_used_idx < it->second+1){
                ans++;
                last_used_idx = i;
            }else if(last_used_idx < 0 && high_prefix_sum == target){
                ans++;
                last_used_idx = i;
            }
            
            low_prefix_sum2last_idx[high_prefix_sum] = i;//NOTE: greedy priority
        }
        return ans;
    }
};
