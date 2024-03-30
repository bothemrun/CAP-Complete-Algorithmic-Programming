//knapsack dp

//[A] knapsack of sums >= k, see sums >= k as sum == k.
//1. TLE, since max sum 1e12

//[B] sum of knapsack of sums < k.

//[C] for sum_A >= k & sum_B < k?
//ans = 2^n - invalid - invalid

//[D] what about the intersection of sums < k?
//1. if we rule out all sum < 2*k at first,
//2. then the intersection doesn't exist in this case.

//O(n * k)

#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();


class Solution {
public:
    const int notyet = (-1);
    const long long mod = (long long)1e9 + 7;
    vector<vector<int>> memo;

    int knapsack(const vector<int>& nums, int i, int sum){
        if(i==(-1)) return sum==0;

        if(sum<0) return 0;

        assert(i>=0 && sum>=0);
        if(memo[i][sum] != notyet) return memo[i][sum];

        return memo[i][sum] = (
            knapsack(nums, i-1, sum) +
            knapsack(nums, i-1, sum - nums[i])
        )%mod;
    }

    int pow_mod(long long a, int b){
        if(b==0) return 1;

        long long res = pow_mod(a, b/2);
        res = (res*res)%mod;

        if(b%2==1) return (res*a)%mod;
        else return res;
    }

    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();

        long long all_sum = 0;
        for(const int& x: nums) all_sum += x;
        if(all_sum < 2*k) return 0;


        memo.resize(n, vector<int>(k+1, notyet));

        int invalid = 0;
        for(int sum=0;sum<k;sum++)
            invalid = (
                invalid +
                knapsack(nums, n-1, sum)
            )%mod;
        
        int all = pow_mod(2, n);

        return ( (all - invalid - invalid)%mod + mod )%mod;
    }
};
