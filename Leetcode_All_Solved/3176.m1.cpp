//m1
//[A] O(k*n^2)
//wisdompeak DP Basic II


//[B] from m0 to m1:

//1. instead of diff from 0 to k, here the diff is from k to 0,
//and i from n-1 to 0

//2. dp[i][diff] := at most "diff" different pairs available, 
//not exactly diff different pairs in m0.

class Solution {
public:
    const int notyet = (-1);
    vector<vector<int>> memo;
    
    int enum_prefix_end(const vector<int>& nums, int i, int diff){
        if(i<0) return 0;
        if(diff<0) return 0;

        if(memo[i][diff] != notyet) return memo[i][diff];

        int ret = 1; //not 0
        for(int j=0;j<i;j++){
            //nums[i] counted here.
            if(nums[j] == nums[i]){
                ret = max(
                    ret,
                    1 + enum_prefix_end(nums, j, diff)
                );
            }else{
                ret = max(
                    ret,
                    1 + enum_prefix_end(nums, j, diff-1)
                );
            }
        }
        return memo[i][diff] = ret;
    }

    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();

        memo.resize(n, vector<int>(k+1, notyet));
        
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(
                ans,
                enum_prefix_end(nums, i, k)
            );
        }
        return ans;
    }
};
