#define MODULO (1000000000+7)
#define mod 2
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        //all in mod 2
        long long ans = 0;
        vector<int> low_prefix_sum(2,0);//remainder: 0 or 1
        int cur_prefix_sum = 0;
        int target = 1;
        for(const int& x:arr){
            cur_prefix_sum = (cur_prefix_sum + x)%mod;
            
            if(cur_prefix_sum == target)ans++;
            
            if( low_prefix_sum[ (cur_prefix_sum-target + mod)%mod ] > 0) ans += low_prefix_sum[ (cur_prefix_sum-target + mod)%mod ];
            
            low_prefix_sum[ cur_prefix_sum ]++; //update
        }
        return ans%MODULO;
    }
};
