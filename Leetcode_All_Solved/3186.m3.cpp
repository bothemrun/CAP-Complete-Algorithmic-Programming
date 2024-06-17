//m3
//1. optimization --> dp or greedy

//2. dp with binary searching the next

//3. preprocessing sorting in O(nlogn)

//4. TLE for top down dp

//5. optimization: use j's monotonicity.

#define Memo(i) ( (i>=0)? memo[i]:0 )
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
        unordered_map<long long, long long> p2sum;
        for(const int& p: power) p2sum[p] += (long long)p;

        int n = p2sum.size();
        vector<long long> uni_p(n);
        int p_i = 0;
        for(const auto& [p, c]: p2sum){
            uni_p[p_i++] = p;
        }

        sort(uni_p.begin(), uni_p.end());

        vector<long long> memo(n);

        //5. optimization: use j's monotonicity.
        int j = 0;

        for(int i=0;i<n;i++){

            while(j<i && !( uni_p[j] >= uni_p[i]-2 ) ){
                j++;
            }

            //choose or skip
            memo[i] = max(
                Memo(i-1),
                p2sum[ uni_p[i] ] + Memo(j-1)
            );
        }

        return Memo(n-1);
    }
};
