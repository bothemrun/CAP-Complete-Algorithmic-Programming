//m0
//1. O(nlogn) by 1D line sweep

//2. dp thinking: for dp[i]'s segment, it can connect with segment dp[i-1] or not.
//2.a. so dp[i] = dp[i-1] + dp[i-1]
//2.b. so the answer is 2^(segment count - 1)

#define PII pair<int,int>
#include<algorithm>
#include<assert.h>
#include<unordered_map>
#include<utility>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    long long pow_mod(const long long& base, const int& p, const long long& mod){
        if(p == 0) return 1LL;

        long long half = pow_mod(base, p/2, mod);
        if(p%2 == 0) return (half*half)%mod;
        else return ( (half*half)%mod * base )%mod;
    }

    int numberOfGoodPartitions(vector<int>& nums) {
        int n = nums.size();

        //num --> (first index, last index)
        unordered_map<int, PII> first_last;
        for(int i=0;i<n;i++){
            const int& x = nums[i];
            if(first_last.count(x) == 0){
                first_last[x] = PII(i, i);
            }else{
                first_last[x].second = i;
            }
        }

        vector<PII> line_sweep;
        for(const auto& [x, p]: first_last){
            line_sweep.push_back( PII(p.first, 1) );
            line_sweep.push_back( PII(p.second, -1) );
        }
        auto cmp = [](const PII& a, const PII& b){
            if(a.first != b.first) return a.first < b.first;
            else return a.second > b.second;
            //+1 goes before -1
        };
        sort(line_sweep.begin(), line_sweep.end(), cmp);


        int segment = 0;
        int sweep = 0;
        for(const auto& [pos, delta]: line_sweep){
            sweep += delta;
            assert(sweep >= 0);
            if(sweep == 0) segment++;
        }

        
        return pow_mod(2, segment-1, (long long)1e9 + 7LL);
    }
};
