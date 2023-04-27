//m1
//recursion with memo
//NOTE: greedy proof: why linear like subarray?

//proof: if there's a non-increasing slide, for previous down states at [i-k], the numbers between (i-k, i-k+1, ..., i-2, i-1) <= nums[i],
//so the up state at [i] can continue to use the down state at [i-k].
#define notyet (-1)
#include<algorithm>
enum{
    state_down,
    state_up
};
class Solution {
public:
    vector<vector<int>> memo;
    int wiggle(const vector<int>& nums, const int& i, const int& state){
        if(i < 0)return 0;
        if(i == 0)return 1;
        if(memo[i][state] != notyet)return memo[i][state];

        memo[i][state] = wiggle(nums, i-1, state);
        //NOTE: 2 options even if ascending !!!
        if(nums[i-1] < nums[i] && state == state_up)
            memo[i][state] = max(
                wiggle(nums, i-1, state),
                1 + wiggle(nums, i-1, state_down)
            );
        else if(nums[i-1] > nums[i] && state == state_down)
            memo[i][state] = max(
                wiggle(nums, i-1, state),
                1 + wiggle(nums, i-1, state_up)
            );
        return memo[i][state];
    }

    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        memo = vector<vector<int>>(n, vector<int>(2, notyet));
        return max(
            wiggle(nums, n-1, state_down),
            wiggle(nums, n-1, state_up)
        );
    }
};
