//m0
//like merge 2 sorted lists in O(m+n)
//it doesn't follow the required O(log(m+n))

#include<assert.h>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int m, n;
    inline int kth_merge2sorted(const vector<int>& nums1, const vector<int>& nums2, const int& k){
        assert(0<=k && k<m+n);

        int i=0, j=0;
        int idx=0;

        while(i<m && j<n){
            if(nums1[i] < nums2[j]){
                if(idx == k) return nums1[i];

                i++;
            }else{
                if(idx == k) return nums2[j];

                j++;
            }

            idx++;
        }

        if(i<m){
            assert(k-n >= 0);
            return nums1[k - n];
        }else{
            assert(k-m >= 0);
            return nums2[k - m];
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        m = nums1.size();
        n = nums2.size();

        if((m+n)%2 == 1)
            return kth_merge2sorted(nums1, nums2, (m+n-1 + 0)/2 );
        else return (
            kth_merge2sorted(nums1, nums2, (m+n-1 + 0)/2 ) +
            kth_merge2sorted(nums1, nums2, (m+n-1 + 0)/2 + 1 )
        )/2.0;
    }
};
