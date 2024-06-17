//m4

//1. optimization --> dp or greedy
//2. preprocessing sorting in O(nlogn)

#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    unordered_map<long long, long long> p2sum;
    vector<long long> uni_p;

    const long long notyet = (-1);
    vector<long long> memo;

    long long enum_choice(int i){
        if(i<0) return 0;

        if(memo[i] != notyet) return memo[i];

        //O(1)
        int j = i;
        while(j>=0 && !( uni_p[j] < uni_p[i] - 2 ) ){
            j--;
        }

        return memo[i] = max(
            enum_choice(i-1),
            p2sum[ uni_p[i] ] +
            enum_choice(j)
        );
    }

    long long maximumTotalDamage(vector<int>& power) {
        for(const int& p: power) p2sum[p] += (long long)p;

        int n = p2sum.size();
        uni_p.resize(n);
        int p_i = 0;
        for(const auto& [p, c]: p2sum){
            uni_p[p_i++] = p;
        }

        sort(uni_p.begin(), uni_p.end());

        memo.resize(n, notyet);
        return enum_choice(n-1);
    }
};
