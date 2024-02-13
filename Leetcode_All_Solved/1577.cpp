//O(n^2)
#include<unordered_map>

class Solution {
public:
    inline int loop2(const vector<int>& a, const vector<int>& b){
        unordered_map<long long, int> cnt;
        for(const int& x: a) cnt[ (long long)x * (long long)x ]++;

        int ans = 0;
        int n = b.size();
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                ans += cnt[ (long long)b[i] * (long long)b[j] ];
        return ans;
    }

    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        return loop2(nums1, nums2) + loop2(nums2, nums1);
    }
};
