#include<algorithm>
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> ans;
        int mask = (1 << maximumBit) - 1;
        int prefix_xor = 0;//identity for xor
        for(int i=0;i<nums.size();i++){
            prefix_xor ^= nums[i];
            ans.push_back( (~prefix_xor) & mask );
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
