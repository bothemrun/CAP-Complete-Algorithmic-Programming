//m5

//1. optimization --> dp or greedy
//2. preprocessing sorting in O(nlogn)

#define Memo(i) ( (i>=0)? memo[i]:0LL )
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
        for(const int& p: power) p2sum[p] += p;

        int n = p2sum.size();
        vector<long long> uni_p(n);
        int p_i = 0;
        for(const auto& [p, s]: p2sum){
            uni_p[p_i++] = p;
        }

        sort(uni_p.begin(), uni_p.end());


        vector<long long> memo(n);
        for(int i=0;i<n;i++){
            //in O(1)
            int j = i;
            while(j>=0 && !( uni_p[j] < uni_p[i] - 2 ) ){
                j--;
            }

            //choose or skip
            memo[i] = max(
                Memo(i-1),
                p2sum[ uni_p[i] ] + Memo(j)
            );
        }

        return Memo(n-1);
    }
};
