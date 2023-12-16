//1. since n = 14 small, bitmask dp
//2. O(2^14 * 14^2) = O(3e6)

#define notyet (-1)
#include<assert.h>
#include<algorithm>
#include<limits.h>

class Solution {
public:
    int n;
    vector<vector<int>> memo;

    int enum_subset(const vector<int>& nums1, const vector<int>& nums2, const int& i, const int& mask){

        assert(i+1 == __builtin_popcount(mask) );

        if(i==(-1)) return 0;

        if(memo[i][mask] != notyet) return memo[i][mask];

        int sum = INT_MAX;
        for(int j=0;j<n;j++)if( mask & (1<<j) ){
            sum = min(
                sum,
                enum_subset(nums1, nums2, i-1, mask & (~(1<<j)) ) +
                ( nums1[i] ^ nums2[j] )
            );
        }

        return memo[i][mask] = sum;
    }

    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();

        memo.resize(n, vector<int>(1<<n, notyet));
        return enum_subset(nums1, nums2, n-1, (1<<n) - 1);
    }
};
