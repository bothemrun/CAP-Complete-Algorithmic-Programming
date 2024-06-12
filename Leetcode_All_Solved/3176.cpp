//O(k*n^2)
//wisdompeak DP Basic II

class Solution {
public:
    const int notyet = (-1);
    vector<vector<int>> memo;
    int max_diff;

    int enum_prefix(const vector<int>& nums, int i, int diff){
        //dp definition: nums[i] not taken into account by later indices yet.
        if(i<0) return 0;

        if(memo[i][diff] != notyet) return memo[i][diff];

        int ret = 1;//trap: not 0
        for(int j=i-1;j>=0;j--){
            if(nums[j] == nums[i]){
                //nums[i] taken into account here.
                ret = max(
                    ret,
                    1 + enum_prefix(nums, j, diff)
                );
            }else if(diff+1 <= max_diff){
                ret = max(
                    ret,
                    1 + enum_prefix(nums, j, diff+1)
                );
            }
        }

        return memo[i][diff] = ret;
    }

    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        this->max_diff = k;

        memo.resize(n, vector<int>(max_diff+1, notyet));

        int ans = 0;
        //trap: not return enum_prefix(nums, n-1, 0);
        for(int i=0;i<n;i++)
            ans = max(
                ans,
                enum_prefix(nums, i, 0)
            );
        return ans;
    }
};
