//m4
//knapsack dp

//use hash maps instead of calculating tricky memo size

#include<unordered_map>

class Solution {
public:
    int n;
    unordered_map< int, unordered_map<int, int> > memo;

    int enum_tree(const vector<int>& nums, const int& target, const int& i, const int& subset_sum){
        if(i==n) return subset_sum == target;

        if(memo[i].count(subset_sum) != 0) return memo[i][subset_sum];

        //choose or skip
        return memo[i][subset_sum] = 
            enum_tree(nums, target, i+1, subset_sum - nums[i]) +
            enum_tree(nums, target, i+1, subset_sum + nums[i]);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        this->n = nums.size();

        return enum_tree(nums, target, 0, 0);
    }
};
