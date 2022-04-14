#include<limits.h>
class Solution {
private:
    int max_or = INT_MIN;
    int max_or_count = 0;
    void n_ary_tree_not_choose_back(const vector<int>& nums, int cur_or=0, int begin=0){
        if(!(begin == 0)){
            if(max_or < cur_or){
                max_or = cur_or;
                max_or_count = 1;
            }else if(max_or == cur_or)
                max_or_count++;
        }
        
        for(int i=begin;i<nums.size();i++)
            n_ary_tree_not_choose_back(nums, cur_or | nums[i], i + 1);
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        n_ary_tree_not_choose_back(nums);
        return max_or_count;
    }
};
