#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int minSteps(string s, string t) {
        int n = s.size();
        int s_cnt[256] = {0};
        int t_cnt[256] = {0};
        for(const char& c: s) s_cnt[c]++;
        for(const char& c: t) t_cnt[c]++;

        int ans = 0;
        for(char c='a';c<='z';c++)if( s_cnt[c] < t_cnt[c] )
            ans += t_cnt[c] - s_cnt[c];
        
        return ans;
    }
};
