//m1
//recursion with memo.  knapsack dp.
#define notyet (-1)
#define max_sum 20002
#define offset 20002
#define max_size (max_sum + offset + 2)
class Solution {
public:
    vector<vector<int>> memo;
    int knapsack(const vector<int>& nums, const int& i, const int& target){
        if(i < 0) return target == 0;

        if(memo[i][target + offset] != notyet) return memo[i][target + offset];

        return memo[i][target + offset] = (
            knapsack(nums, i-1, target - nums[i] ) +
            knapsack(nums, i-1, target + nums[i])
        );
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        memo.resize(n, vector<int>(max_size, notyet));
        return knapsack(nums, n-1, target);
    }
};
