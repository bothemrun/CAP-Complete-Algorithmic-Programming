//prefix hash of remainder O(n)

#define mod 60
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        //remainder to count, prefix hash
        int prefix_hash[mod] = {0};
        int ans = 0;
        for(const int& t: time){
            ans += prefix_hash[ (mod - t%mod)%mod ];

            prefix_hash[t%mod]++;
        }

        return ans;
    }
};
