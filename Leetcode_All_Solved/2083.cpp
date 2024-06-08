//O(n)
#define comb(a, b) ( a*(a-1)/2 )
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    long long numberOfSubstrings(string s) {
        long long cnt[256] = {0};
        for(const char& c: s) cnt[c]++;

        long long ans = (long long)s.size();

        for(char c='a';c<='z';c++)
            ans += comb(cnt[c], 2LL);
        return ans;

    }
};
