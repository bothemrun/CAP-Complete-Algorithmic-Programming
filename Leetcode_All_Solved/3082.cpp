//m0
//Thinking Process:


//[A] Reversed Thinking From Results:
//1. how does a good subsequence (whose sum is k) contributes to the final answer?
//2. len := length of the good subsequence, contribution = 2^(n - len).


//[B] Now a Knapsack DP Problem.
//1. knapsack from 0.
//2. knapsack(i, sum, taken) --> taken == len.


//[C] pow mod
//1. can't use C++ math.h pow() --> 'cuz the scientific notation loses precision

//O(n * max sum * max taken)= O(nkn)

class Solution {
public:
    const long long mod = (long long)1e9 + 7;
    vector<vector<vector<long long>>> memo;
    int n;
    const long long notyet = (-1);

    inline long long pow2mod(const int& p, const long long& base=2){
        //base^p
        if(p==0) return 1;

        long long res = pow2mod(p/2);
        res = (res*res)%mod;

        if(p%2==1) res = (res * base)%mod;
        return res;
    }

    long long knapsack_enum_tree(const vector<int>& nums, const int& target, const int& i, const int& sum, const int& taken){
        //prune
        if(sum > target) return 0;
        if(i==n){
            if(sum == target) return pow2mod(n - taken);
            else return 0;
        }

        if(memo[i][sum][taken] != notyet) return memo[i][sum][taken];

        //enum tree, choose or skip
        return memo[i][sum][taken] = (
            knapsack_enum_tree(nums, target, i+1, sum, taken) +
            knapsack_enum_tree(nums, target, i+1, sum + nums[i], taken + 1)
        )%mod;
    }

    int sumOfPower(vector<int>& nums, int k) {
        n = nums.size();
        memo.resize(n, vector<vector<long long>>(k+1, vector<long long>(n, notyet) ) );
        return knapsack_enum_tree(nums, k, 0, 0, 0);
    }
};
