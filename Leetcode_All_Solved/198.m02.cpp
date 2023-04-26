//m02
//bottom up, O(1) space, viewpoint from top down dp
#define IDX(i) ((i)%2)
//#define IDX_wrong(i) (i%2)
#include<algorithm>
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(2, vector<int>(2));
        dp[IDX(0)] = {0, nums.front()};//n>=1

        for(int i=1;i<n;i++){
            printf("%d %d %d\n", i, IDX(i), IDX(i-1));
            dp[IDX(i)][1] = nums[i] + dp[IDX(i-1)][0];
            dp[IDX(i)][0] = max({ dp[IDX(i-1)][0], dp[IDX(i-1)][1] });
        }
        return max({ dp[IDX(n-1)][0], dp[IDX(n-1)][1] });
    }
};
