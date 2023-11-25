//Thinking Process

//[A] count ways for random input: dp

//[B] two parts: first range
//1. there are two parts: range & sum diff.
//2. for range --> end at i

//[C] dp(end at i, sum of nums1, sum of nums2)
//1. O(max_sum^2 * n) = O(1e4 ^ 2 * 1e2)
//2. condition 3 can be characterized.

//[D] dp(end at i, sum diff of nums1 - nums2)
//1. O(max_sum * n) = O(1e4 * 1e2)
//2. condition 3 can still be characterized.

#define notyet (-1)
#define max_sum (int)1e4
#define offset max_sum
#define memo_size (offset + max_sum + 3)

class Solution {
public:
    const int mod = (int)1e9 + 7;
    vector<vector<int>> memo;

    int enum_choice(const vector<int>& nums1, const vector<int>& nums2, const int& i, const int& diff){

        if(i==(-1)) return 0;

        if(memo[i][diff + offset] != notyet) return memo[i][diff + offset];

        int ret = (
            enum_choice(nums1, nums2, i-1, diff - nums1[i] ) +
            enum_choice(nums1, nums2, i-1, diff + nums2[i] )
        )%mod;

        //NOTE: crucial left ends
        ret += (diff == nums1[i] );
        ret += (diff == (-nums2[i]) );

        return memo[i][diff + offset] = ret;
    }

    int countSubranges(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        memo.resize(n, vector<int>(memo_size, notyet));

        int ans = 0;
        for(int i=0;i<n;i++)
            ans = (
                ans +
                enum_choice(nums1, nums2, i, 0)
            )%mod;

        return ans;
    }
};
