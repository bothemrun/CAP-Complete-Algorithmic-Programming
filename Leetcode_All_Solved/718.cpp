#include<algorithm>
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        //NOTE: dp[i][j]: longest common subarray for nums1[:i] & nums2[:j]
        //so ans = max(all dp[i][j])
        int lcsa = 0;
        vector<vector<int>> dp(m, vector<int>(n,0) );
        for(int i=0;i<m;i++)if(nums1[i] == nums2[0]){
            dp[i][0] = 1;
            lcsa = max(lcsa, 1);
        }
        for(int j=0;j<n;j++)if(nums1[0] == nums2[j]){
            dp[0][j] = 1;
            lcsa = max(lcsa, 1);
        }
        for(int i=1;i<m;i++)for(int j=1;j<n;j++)if(nums1[i] == nums2[j]){
            dp[i][j] = 1 + dp[i-1][j-1];
            lcsa = max(lcsa, dp[i][j]);
        }
        return lcsa;
    }
};
