//O(n) prefix hash of prefix sum in modulo
//all remainder in 0~(mod-1), so only 1 possibility.
#include<unordered_map>
#include<assert.h>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();

        long long ans = 0;
        //NOTE: prefix hash of prefix sum of count in modulo
        unordered_map<int, long long> prefix_hash;
        int prefix_sum_cnt_mod = 0;

        for(const int& x: nums){
            
            if(x%modulo == k)
                prefix_sum_cnt_mod = (1 + prefix_sum_cnt_mod)%modulo;
            
            int prev_cnt = (
                    (prefix_sum_cnt_mod - k)%modulo + modulo
                )%modulo;
            assert(0<=prev_cnt);
            ans += prefix_hash[ prev_cnt ];

            if(prefix_sum_cnt_mod == k) ans++;

            //update
            prefix_hash[ prefix_sum_cnt_mod ]++;
        }

        return ans;
    }
};
