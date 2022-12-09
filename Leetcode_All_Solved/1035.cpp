//NOTE: longest common subsequence
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> dp_lcs(m + 1, vector<int>(n + 1));
        for(int i=0;i<=m;i++)dp_lcs[i][0] = 0;
        for(int j=0;j<=n;j++)dp_lcs[0][j] = 0;

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                dp_lcs[i][j] = max( 
                    ( (nums1[i-1]==nums2[j-1])? 1:0 ) + 
                    dp_lcs[i-1][j-1], 
                    max(dp_lcs[i][j-1], dp_lcs[i-1][j]) 
                    );
            }
        }
        return dp_lcs[m][n];
    }
};
