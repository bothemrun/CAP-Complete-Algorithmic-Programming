//O(n)

#define comb2(a) (a*(a-1LL)/2LL)
#define full_day 24
#include<iostream>
auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        long long cnt[full_day] = {0};

        for(const int& h: hours){
            cnt[h%full_day]++;
        }

        long long ans = comb2(cnt[0]) + comb2(cnt[12]);

        for(int h=1;h<=11;h++){
            ans += cnt[h] * cnt[full_day-h];
        }
        
        return ans;
    }
};
