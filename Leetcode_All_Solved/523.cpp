#include<unordered_set>
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        //NOTE: all in remainders
        unordered_set<unsigned int> mod_pre2_prefix_sum = {0};
        unsigned int high_prefix_sum = nums[0]%k;
        for(int i=1;i<nums.size();i++){
            unsigned int pre1_high_prefix_sum = high_prefix_sum;
            high_prefix_sum = (high_prefix_sum + nums[i])%k;
            //NOTE: with same remainders
            if( mod_pre2_prefix_sum.count( high_prefix_sum ) )return true;
            
            mod_pre2_prefix_sum.insert( pre1_high_prefix_sum );
        }
        return false;
    }
};
