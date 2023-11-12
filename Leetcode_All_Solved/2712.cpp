//m0
//Thinking Process

//[A] Proof Existence
//1. WLOG, we want all to be 1 (0 also works).
//2. we apply the prefix operations from i=n-1 to 0
//3. for the operation at i, we only invert only if s[i] is 0.
//4. finally at i=0, this is the base case.
//4. by induction, we proved its existence.


//[B] inversion operations are independent
//1. so we can separate these 2 types of prefix & suffix operations.

//[C] enum breakpoints
//1. first we build prefix & suffix dp in O(n).
//2. then enum breakpoints like prefix_dp[i] + suffix_dp[i+1]

//O(n)

#define notyet (-1)
#include<limits.h>
#include<algorithm>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    string s;
    int n;
    inline void do_prefix(vector<vector<long long>>& memo){
        for(int i=0;i<n;i++){
            enum_prefix(memo, i, true);
            enum_prefix(memo, i, false);
        }
    }

    long long enum_prefix(vector<vector<long long>>& memo, const long long& i, bool bit){
        if(i<0) return 0;

        if(memo[i][bit] != notyet) return memo[i][bit];


        bool good = (bit && s[i]=='1') || (!bit && s[i]=='0');
        if(good)
            return memo[i][bit] = enum_prefix(memo, i-1, bit);
        else return memo[i][bit] = (i+1) + enum_prefix(memo, i-1, !bit);
    }

    long long minimumCost(string s_input) {
        s = s_input;
        n = s.size();

        vector<vector<long long>> prefix(n, vector<long long>(2, notyet));
        vector<vector<long long>> suffix(n, vector<long long>(2, notyet));

        do_prefix(prefix);

        reverse(s.begin(), s.end());
        do_prefix(suffix);
        reverse(suffix.begin(), suffix.end());


        long long ans = LLONG_MAX;
        for(int i=0;i+1<n;i++){
            ans = min({
                ans,
                prefix[i][true] + suffix[i+1][true],
                prefix[i][false] + suffix[i+1][false]
            });
        }

        //edge
        return min({
            ans,
            prefix.back()[true],
            prefix.back()[false],

            suffix.front()[true],
            suffix.front()[false]
        });
    }
};
