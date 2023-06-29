//prefix hash.
#include<unordered_map>
#include<stdlib.h>
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,int> num2last_idx;

        for(int i=0;i<n;i++){
            if(
                num2last_idx.count( nums[i] ) != 0 &&
                abs(
                    i - num2last_idx[ nums[i] ]
                ) <= k
            ) return true;

            num2last_idx[ nums[i] ] = i;
        }
        return false;
    }
};
