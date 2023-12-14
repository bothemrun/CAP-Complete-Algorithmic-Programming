//[A] O(m^2) dp.
//like palindrome dp, shrinking dp[i, j].

//[B] no greedy algorithm
//1. if we choose the larger of start / end of nums,
//2. we don't know if the matched nums[i] / nums[i+1] for the next is a better match.

//[C] Memory Limit Exceeded
//1. use a tree map for a hash map of pairs/ vectors.
//1.a. induces an extra O(logm) complexity.
//2. use a macro to convert memo index.
//2.a. so still use a vector of O(m^2)

#define Memo(i, j) ( memo[i][ (n-1) - j ] )

#define notyet INT_MIN
#include<limits.h>
#include<assert.h>
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
    int m, n;
    //no overflow
    vector<vector<int>> memo;

    int enum_shrink(const vector<int>& nums, const vector<int>& mul, const int& i, const int& j){

        int k = (i - 0) + ((n-1) - j);
        assert(k>=0);
        if(k >= m){
            assert(k == m);
            return 0;
        }

        assert(i <= j);//since n >= m

        if(Memo(i, j) != notyet) return Memo(i, j);

        return Memo(i, j) = max(
            mul[k] * nums[i] +
            enum_shrink(nums, mul, i+1, j),
            
            mul[k] * nums[j] +
            enum_shrink(nums, mul, i, j-1)
        );
    }

    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        n = nums.size();
        m = multipliers.size();

        //NOTE: MLE:
        //memo.resize(n, vector<int>(n, notyet));
        memo.resize(m, vector<int>(m, notyet));

        return enum_shrink(nums, multipliers, 0, n-1);
    }
};
