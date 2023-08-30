//m0

//keep 2 states: odd & even length subsequence

//naive method: like longest increasing subesquence, use O(n^2).
// LIS ending at i is obtained by enumerating previous j

//but how to improve to O(n)?
//define the dp[i] as the answer for nums[0, i], and the best subsequence not necessarily end at i.

//why doesn't it need O(n^2) ending at i dp definition like LIS ?
//'cuz LIS needs to know the last element to maintain the monoticity,
//while this problem doesn't need to know the last element. it just want sum.

#define notyet INT_MIN
#include<limits.h>
#include<algorithm>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

enum{
    EVEN,
    ODD
};

class Solution {
public:
    vector<vector<long long>> memo;

    long long enum_len_parity(const vector<int>& nums, const int& i, const int& parity){
        if(i==0){
            return (parity==ODD)? nums[i]:0;
        }

        if(memo[i][parity] != notyet) return memo[i][parity];

        long long even_len = enum_len_parity(nums, i-1, EVEN);
        long long odd_len = enum_len_parity(nums, i-1, ODD);

        if(parity == ODD)
            return memo[i][parity] = max(
                odd_len,
                even_len + nums[i]
            );
        else
            return memo[i][parity] = max(
                even_len,
                odd_len - nums[i]
            );
    }

    long long maxAlternatingSum(vector<int>& nums) {
       int n = nums.size();

       memo.resize(n, vector<long long>(2, notyet));
       return max(
           enum_len_parity(nums, n-1, EVEN),
           enum_len_parity(nums, n-1, ODD)
       );
    }
};
