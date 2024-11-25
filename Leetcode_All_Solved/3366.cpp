class Solution {
public:
    int n;
    const int notyet = (-1);
    vector<vector<vector<int>>> memo;
    int enum5(const vector<int>& nums, const int k, int i, int op1, int op2){
        if(i==n){
            return 0;
        }
        if(memo[i][op1][op2] != notyet) return memo[i][op1][op2];
        
        int ret = enum5(nums, k, i+1, op1, op2) + nums[i];
        if(op1 > 0){
            ret = min(
                ret,
                enum5(nums, k, i+1, op1-1, op2) + nums[i]/2 + (nums[i]%2)
            );
        }
        if(op2 > 0 && nums[i] >= k){
            ret = min(
                ret,
                enum5(nums, k, i+1, op1, op2-1) + nums[i]-k
            );
        }
        if(op1 > 0 && op2 > 0){
            //2 edge cases
            if(nums[i] >= k){
                int x = nums[i] - k;
                //assert(x >= 0);
                x = x/2 + (x%2);
                ret = min(
                    ret,
                    enum5(nums, k, i+1, op1-1, op2-1) + x
                );
            }
            if( nums[i]/2 + (nums[i]%2) >= k ){
                int x = nums[i]/2 + (nums[i]%2);
                //assert(x >= k);
                x -= k;
                ret = min(
                    ret,
                    enum5(nums, k, i+1, op1-1, op2-1) + x
                );
            }
        }
        return memo[i][op1][op2] = ret;
    }
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        this->n = nums.size();
        memo.resize(n, vector<vector<int>>(op1+1, vector<int>(op2+1, notyet ) ) );
        return enum5(nums, k, 0, op1, op2);
    }
};
