//m0
//O(10*n)

#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long ans = 0;

        int prefix_sum = 0;
        const int max_bits = 10;
        int cnt[1<<max_bits] = {0};

        for(const char& c: word){
            prefix_sum ^= (1 << (c-'a'));

            //[j, i], j>=1
            ans += cnt[prefix_sum];

            for(int b=0, mask=1;b<max_bits;b++, mask<<=1){
                ans += cnt[ prefix_sum ^ mask ];
            }

            //[0, i]
            ans += prefix_sum==0 || __builtin_popcount(prefix_sum)==1;

            //update
            cnt[prefix_sum]++;
        }

        return ans;
    }
};
