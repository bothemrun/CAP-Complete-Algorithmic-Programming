//O(n)

//1. nums[i] xor x can make any binary representation.
//2. but the bottleneck is the and part.
//3. so nums[i] and (nums[i] xor x) can keep the set bits or unset the set bits of nums[i],

//4. but what is the max xor result?
//4.1. the result with all bits set.
//4.2. for example, each nums[i] make the i'th bit set,
//4.3. and other nums all 0, ('cuz unset bit 0 is the identity for xor)

//5. if two nums originally have the i'th bit set, then just have 1 set, and the other unset its i'th bit.

//6. so the max result is produced by checking if any original nums has the i'th bit set for each i'th bit
//6.1. that is, bitwise or of all the i'th bit from all nums.

class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int ans = 0;
        for(const int& x: nums) ans |= x;
        return ans;
    }
};
