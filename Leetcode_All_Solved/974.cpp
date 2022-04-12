class Solution {
private:
    int mod;
    inline long long nonneg_mod(const long long& x){
        return (x%mod + mod)%mod;
    }
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        mod = k;
        
        int ans = 0;
        //NOTE:
        unordered_map<long long,int> prefix_sum_mod2count;
        long long prefix_sum_mod = 0;
        for(int i=0;i<n;i++){
            prefix_sum_mod = nonneg_mod(prefix_sum_mod + nums[i]);//update prefix sum of mod
            if( prefix_sum_mod == 0 )ans++;
            
            unordered_map<long long,int>::iterator f = prefix_sum_mod2count.find( prefix_sum_mod );
            if(f != prefix_sum_mod2count.end()) ans += f->second;
            
            //update hash map of prefix sum
            if(f != prefix_sum_mod2count.end()) f->second++;
            else prefix_sum_mod2count[ prefix_sum_mod ] = 1;
        }
        return ans;
    }
};
