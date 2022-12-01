#include<unordered_map>
#include<algorithm>
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int max_len = 0;
        unordered_map<long long,int> low_prefix_sum2idx;
        //int high_prefix_sum = 0;
        long long high_prefix_sum = 0;
        for(int i=0;i<nums.size();i++){
            high_prefix_sum += nums[i];
            
            if(high_prefix_sum == k)
                max_len = max(max_len, i + 1);
            if( low_prefix_sum2idx.count(high_prefix_sum - k) != 0 )
                max_len = max(max_len, i - low_prefix_sum2idx[high_prefix_sum - k] ); // + 1 );
            
            //update
            if(low_prefix_sum2idx.count(high_prefix_sum) == 0)
                low_prefix_sum2idx[high_prefix_sum] = i;
        }
        return max_len;
    }
};
