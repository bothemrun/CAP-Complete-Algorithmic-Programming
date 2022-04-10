//m1
#include<unordered_map>
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<long long,int> low_prefix_sum2times = {{0, 1}};//NOTE: low can be null sum. high sum idx > low sum idx.
        long long high_prefix_sum = 0;
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            high_prefix_sum += nums[i];
            unordered_map<long long,int>::iterator low = low_prefix_sum2times.find( high_prefix_sum - k );
            if(low != low_prefix_sum2times.end()) ans+= low->second;
            
            if(low_prefix_sum2times.count(high_prefix_sum)) low_prefix_sum2times[high_prefix_sum]++;
            else low_prefix_sum2times[high_prefix_sum] = 1;
        }
        return ans;
    }
};
