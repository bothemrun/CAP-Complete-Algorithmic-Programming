#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        const int max_bits = 32;
        vector<int> cnt(max_bits, 0);
        for(const int& x: nums){
            for(int b=0, mask=1;b<max_bits;b++, mask<<=1)
                cnt[b] += ( (mask & x) != 0 );
        }

        int ans = 0;
        for(int b=0, mask=1;b<max_bits;b++, mask<<=1)
            ans += ( (cnt[b]%2) ^ ( (k&mask) != 0 ) );
        return ans;
    }
};
