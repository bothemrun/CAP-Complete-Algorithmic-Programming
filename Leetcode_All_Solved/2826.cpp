//O(n) dp

class Solution {
public:
    int n;
    vector<vector<int>> memo;
    const int notyet = (-1);

    int enum_subset(const vector<int>& nums, int i, int last=0){
        if(i==n) return 0;

        if(memo[i][last] != notyet) return memo[i][last];

        //skip
        int ret = 1 + enum_subset(nums, i+1, last);

        //choose
        if(last <= nums[i]){
            ret = min(
                ret,
                enum_subset(nums, i+1, nums[i])
            );
        }
        return memo[i][last] = ret;
    }

    int minimumOperations(vector<int>& nums) {
        this->n = nums.size();
        memo.resize(n, vector<int>(3 + 1, notyet));
        return enum_subset(nums, 0);
    }
};
