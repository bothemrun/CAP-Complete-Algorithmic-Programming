//m2
//NOTE: use sum(abs(elements)) to bound memo[][sum], instead of memo[][40002]
//recursion with memo. knapsack dp.
#define notyet (-1)
#include<stdlib.h>
class Solution {
public:
    vector<vector<int>> memo;
    int knapsack(const vector<int>& nums, const int& i, const int& target, const int& offset){
        if(i < 0) return target == 0;

        if(memo[i].at(target + offset) != notyet) return memo[i].at(target + offset);

        return memo[i].at(target + offset) = (
            knapsack(nums, i-1, target + nums[i], offset) +
            knapsack(nums, i-1, target - nums[i], offset)
        );
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        int sum_abs = 0;
        for(const int& num: nums) sum_abs += abs(num);
        int offset = abs(target) + sum_abs + 2;
        int memo_size = 2 * offset + 3;
        //NOTE: use sum(abs(elements)) to bound memo[][sum], instead of memo[][40002]
        memo.resize(n, vector<int>(memo_size, notyet));

        return knapsack(nums, n-1, target, offset);
    }
};
