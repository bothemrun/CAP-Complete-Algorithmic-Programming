#include<limits.h>
#include<unordered_map>
#include<algorithm>
class Solution {
private:
    long long mod;
    inline long long nonneg_mod(const long long& x){
        return (x%mod + mod)%mod;
    }
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        mod = p;
        
        long long all_sum_mod = 0;
        for(int i=0;i<n;i++) all_sum_mod = nonneg_mod(all_sum_mod + nums[i]);
        if(all_sum_mod == 0)return 0;
        
        int min_len = INT_MAX;
        unordered_map<long long,int> prefix_sum_mod2last_idx;
        long long prefix_sum_mod = 0;
        for(int high=0;high<n;high++){
            prefix_sum_mod = nonneg_mod(prefix_sum_mod + nums[high]);
            
            if(prefix_sum_mod == all_sum_mod && high != n-1)
                min_len = min(min_len, high - (0-1));
            
            unordered_map<long long,int>::iterator f = prefix_sum_mod2last_idx.find( nonneg_mod( prefix_sum_mod - all_sum_mod ) );
            if(f != prefix_sum_mod2last_idx.end())
                min_len = min(min_len, high - f->second);
            
            //update on the run, with only the left
            f = prefix_sum_mod2last_idx.find( prefix_sum_mod );
            if(f != prefix_sum_mod2last_idx.end())
                f->second = high;
            else prefix_sum_mod2last_idx[ prefix_sum_mod ] = high;
        }
        
        return (min_len==INT_MAX)? (-1):min_len;
    }
};
