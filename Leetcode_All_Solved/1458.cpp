//O(mn) edit distance. recursion with memo.
#define notyet INT_MAX
#define dont INT_MIN
#include<limits.h>
#include<algorithm>

class Solution {
public:
    //no overflow
    vector<vector<int>> memo;
    int edit_dist(const vector<int>& nums1, const vector<int>& nums2, const int& i, const int& j){
        if(i==0 || j==0) return dont;

        if(memo[i][j] != notyet) return memo[i][j];

        //(1) choose this pair
        //NOTE: clipping
        //NOTE: this ensures "non-empty"
        int ret = nums1[i-1]*nums2[j-1] + max(
            0,
            edit_dist(nums1, nums2, i-1, j-1)
        );

        //(2) not choose this pair
        ret = max({
            ret,
            edit_dist(nums1, nums2, i-1, j),
            edit_dist(nums1, nums2, i, j-1),
        });

        return memo[i][j] = ret;
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        memo.resize(m+1, vector<int>(n+1, notyet));

        return edit_dist(nums1, nums2, m, n);
    }
};
