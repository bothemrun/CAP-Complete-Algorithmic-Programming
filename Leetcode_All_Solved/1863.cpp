class Solution {
private:
    int ans = 0;
    
    void n_ary_tree_not_choose_back(const vector<int>& nums, int cur_ans=0, int begin=0){
        ans += cur_ans;
        
        for(int i=begin;i<nums.size();i++){
            n_ary_tree_not_choose_back(nums, cur_ans ^ nums[i], i + 1);
        }
    }
public:
    int subsetXORSum(vector<int>& nums) {
        n_ary_tree_not_choose_back(nums);
        return ans;
    }
};
