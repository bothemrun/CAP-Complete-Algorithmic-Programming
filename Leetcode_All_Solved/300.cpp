//use Longest Common Subsequence
#include<set>
#include<algorithm>
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        set<int> s;
        for(int num: nums) s.insert(num);
        vector<int> unique_sorted;
        for(set<int>::iterator it=s.begin();it!=s.end();it++)
            unique_sorted.push_back( *it );
        
        int m = unique_sorted.size(), n = nums.size();
        vector<vector<int>> lcs_dp(m + 1, vector<int>(n + 1, 0));
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++){
                if(unique_sorted[i-1] == nums[j-1]) lcs_dp[i][j] = lcs_dp[i-1][j-1] + 1;
                else lcs_dp[i][j] = max(lcs_dp[i-1][j-1], max(lcs_dp[i-1][j], lcs_dp[i][j-1]) );
            }
        return lcs_dp[m][n];
    }
};
