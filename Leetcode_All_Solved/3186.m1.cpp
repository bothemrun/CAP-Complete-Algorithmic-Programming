//m1
//1. optimization --> dp or greedy

//2. dp with binary searching the next

//3. binary search + processing sorting in O(nlogn)

//4. TLE for top down dp

//5. optimization: use j's monotonicity.

#define Memo(i) ( (i>=0)? memo[i]:0 )
#define tll tuple<long long, long long>
#include<tuple>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<long long, long long> p2cnt_map;
        vector<tll> p2cnt;
        for(const int& p: power) p2cnt_map[p]++;

        p2cnt.resize(p2cnt_map.size());
        int p_i = 0;
        for(const auto& [p, c]: p2cnt_map){
            p2cnt[p_i++] = tll(p, c);
        }


        sort(p2cnt.begin(), p2cnt.end());

        int n = p2cnt.size();
        vector<long long> memo(n);

        //5. optimization: use j's monotonicity.
        int j = 0;

        for(int i=0;i<n;i++){

            j = lower_bound(
                p2cnt.begin() + j,
                p2cnt.begin() + i + 1,
                tll( get<0>(p2cnt[i]) - 2, LLONG_MIN )
            ) - p2cnt.begin();

            //choose or skip

            //Memo(i) = max(
            memo[i] = max(
                Memo(i-1),
                get<0>(p2cnt[i]) * get<1>(p2cnt[i]) +
                Memo(j-1)
            );
        }

        return Memo(n-1);
    }
};
