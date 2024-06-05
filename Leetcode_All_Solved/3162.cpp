class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        int ans = 0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                ans += nums1[i] % (k*nums2[j]) == 0;
        return ans;
    }
};
