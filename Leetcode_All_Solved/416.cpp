//m0
//recursion with memo
#define notyet (-1)

class Solution {
public:
    int n;
    vector<vector<int>> memo;
    bool subset_sum(const vector<int>& nums, const int& target_sum, const int& i, const int& cur_sum){
        if(target_sum == cur_sum) return true;
        if(i==n) return false;
        if(cur_sum > target_sum) return false;

        if(memo[i][cur_sum] != notyet) return memo[i][cur_sum];

        //choose or not
        return memo[i][cur_sum] = 
            subset_sum(nums, target_sum, i+1, cur_sum) ||
            subset_sum(nums, target_sum, i+1, cur_sum + nums[i]);
    }
    bool canPartition(vector<int>& nums) {
        n = nums.size();

        int target_sum = 0;
        for(const int& num: nums) target_sum += num;
        if(target_sum%2 != 0) return false;
        target_sum /= 2;

        memo.resize(n, vector<int>(target_sum+1, notyet));
        return subset_sum(nums, target_sum, 0, 0);
    }
};
