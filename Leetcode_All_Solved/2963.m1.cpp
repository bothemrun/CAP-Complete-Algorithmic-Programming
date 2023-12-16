//m1
//O(n)

//1. how to not use O(nlogn) in method m0?
//1.a. how to deal with overlapping?
//1.b. maintain a right_end variable.

//2. dp thinking: for dp[i]'s segment, it can connect with segment dp[i-1] or not.
//2.a. so dp[i] = dp[i-1] + dp[i-1]
//2.b. so the answer is 2^(segment count - 1)

#include<unordered_map>
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
    long long pow_mod(const long long& base, const int& p, const long long& mod){
        if(p==0) return 1LL;

        long long half = pow_mod(base, p/2, mod);
        if(p%2==0) return (half*half)%mod;
        else return ( (half*half)%mod * base )%mod;
    }

    int numberOfGoodPartitions(vector<int>& nums) {
        int n = nums.size();

        //nums --> last index
        unordered_map<int, int> last;
        for(int i=0;i<n;i++) last[nums[i]] = i;


        int segment = 0;
        int right_end = last[ nums.front() ];
        for(int i=0;i<n;i++){
            right_end = max(right_end, last[nums[i]] );

            if(right_end == i){
                segment++;
            }
        }

        return pow_mod(2, segment-1, (long long)1e9 + 7LL);
    }
};
