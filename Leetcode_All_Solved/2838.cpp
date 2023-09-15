//O(mlogm + nlogm) due to sorting and binary searches.

#define PLL pair<long long, long long>

#include<algorithm>
#include<utility>
#include<limits.h>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<long long> maximumCoins(vector<int>& heroes, vector<int>& monsters, vector<int>& coins) {
        int n = heroes.size();
        int m = monsters.size();

        vector<PLL> mon(m);
        for(int i=0;i<m;i++)
            mon[i] = PLL(monsters[i], coins[i]);
        
        auto cmp_lam = [](const PLL& a, const PLL& b){
            return a.first < b.first;
        };
        sort(mon.begin(), mon.end(), cmp_lam);


        vector<long long> prefix(m);
        prefix.front() = mon.front().second;
        for(int i=1;i<m;i++)
            prefix[i] = prefix[i-1] + mon[i].second;
        

        vector<long long> ans(n);
        for(int i=0;i<n;i++){
            int idx = upper_bound(mon.begin(), mon.end(), PLL(heroes[i], LLONG_MAX) ) - mon.begin();
            idx--;

            ans[i] = (idx>=0)? prefix[idx]:0;
        }

        return ans;
    }
};
