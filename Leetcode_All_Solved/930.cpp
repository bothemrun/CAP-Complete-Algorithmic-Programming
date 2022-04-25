#include<unordered_map>
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans = 0;
        int cur_prefix_sum = 0;
        unordered_map<int,int> low_prefix_sum;
        for(int i=0;i<nums.size();i++){
            cur_prefix_sum += nums[i];
            
            if(cur_prefix_sum == goal)ans++;
            
            auto it = low_prefix_sum.find(cur_prefix_sum - goal);
            if(it != low_prefix_sum.end()) ans += it->second;
            
            //update
            if(low_prefix_sum.count(cur_prefix_sum) == 0)low_prefix_sum[cur_prefix_sum] = 1;
            else low_prefix_sum[cur_prefix_sum]++;
        }
        return ans;
    }
};
