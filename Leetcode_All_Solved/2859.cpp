//use gcc __builtin_popcount() or c++20 popcount()

class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int n = nums.size();

        int sum = 0;
        for(int mask=0;mask<n;mask++){
            if( __builtin_popcount(mask) == k )
                sum += nums[mask];
        }
        return sum;
    }
};
