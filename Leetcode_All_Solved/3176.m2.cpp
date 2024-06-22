//m2
//[A] O(k*n^2) bottom up dp
//wisdompeak DP Basic II


//[B] from m0 to m1:

//1. instead of diff from 0 to k, here the diff is from k to 0,
//and i from n-1 to 0

//2. dp[i][diff] := at most "diff" different pairs available, 
//not exactly diff different pairs in m0.

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();

        vector<vector<int>> memo(n, vector<int>(k+1));

        //base case handled

        int ans = 0;
        for(int i=0;i<n;i++){
            for(int diff=0;diff<=k;diff++){

                int ret = 1;//not 0
                for(int j=0;j<i;j++){
                    if(nums[j] == nums[i]){
                        ret = max(
                            ret,
                            1 + memo[j][diff]
                        );
                    }else if(diff-1 >= 0){
                        ret = max(
                            ret,
                            1 + memo[j][diff-1]
                        );
                    }
                }

                memo[i][diff] = ret;
                ans = max(ans, ret);
            }
        }
        return ans;
    }
};
