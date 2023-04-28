//m1
//recursion with memo
//longest common subsequence
#define notyet (-1)
#include<algorithm>
class Solution {
public:
    vector<vector<int>> memo;
    int lcs(const vector<int>& nums1, const vector<int>& nums2, const int& i, const int& j){
        if(i==0 || j==0)return 0;
        if(memo[i][j] != notyet)return memo[i][j];

        //NOTE: all nums or strings 0-indexed
        if(nums1[i-1] == nums2[j-1])
            return memo[i][j] = 1 + lcs(nums1, nums2, i-1, j-1);
        return memo[i][j] = max(
            lcs(nums1, nums2, i-1, j),
            lcs(nums1, nums2, i, j-1)
        );
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        memo.resize(m+1, vector<int>(n+1, notyet));
        return lcs(nums1, nums2, m, n);
    }
};
