//Thinking Process

//[A] reduce subarray size
//1. if we can ensure al subarray with size == 3 are valid,
//2. then valid for any subarrays with size >= 3.

//[B] greedy for min?
//1. greedy counterexample: [k-2, 0, k-3, 0, k-2] with 2+2 > 3.

//[C] so how to handle the effects of choosing nums[i] forwards & backwards?
//1. use "next_good" variable.
//2. dp choose or not dp O(n)


#define window_size 3
#define must_choose_next_good window_size

#define notyet (-1)
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
    vector<vector<long long>> memo;

    long long enum_next_good(const vector<int>& nums, const long long& k, const int& i, const int& next_good){
        //NOTE: no one forwards in front to help me.
        //NOTE: but ok, thanks to if(next_good == must_choose_next_good)
        if(i<0) return 0;

        if(memo[i][next_good] != notyet) return memo[i][next_good];


        bool good = nums[i] >= k;
        if(good)
            return memo[i][next_good] = enum_next_good(nums, k, i-1, 1);
        

        long long cost = k - (long long)nums[i];
        //must choose
        if(next_good == must_choose_next_good)
            return memo[i][next_good] = cost + enum_next_good(nums, k, i-1, 1);
        
        //choose or not
        return memo[i][next_good] = min(
            cost + enum_next_good(nums, k, i-1, 1),
            enum_next_good(nums, k, i-1, next_good + 1)
        );
    }

    long long minIncrementOperations(vector<int>& nums, int k) {
        int n = nums.size();

        memo.resize(n, vector<long long>(must_choose_next_good + 1, notyet));
        return enum_next_good(nums, k, n-1, must_choose_next_good - (window_size-1) );
    }
};
