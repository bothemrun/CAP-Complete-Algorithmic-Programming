//m1
#include<algorithm>
class Solution {
private:
    void backtrack_n_ary_tree_not_choose_back(const vector<int>& nums, vector<vector<int>>& ans, vector<int>& cur_ans,  int begin=0){
        ans.push_back(cur_ans);
        
        //NOTE: subset property. not choose back
        for(int i=begin;i<nums.size();i++){
            cur_ans.push_back(nums[i]);
            backtrack_n_ary_tree_not_choose_back(nums, ans, cur_ans,  i + 1);//NOTE: subset property. not choose back
            cur_ans.pop_back();
            
            //NOTE: neighbor deduplicate in this spot
            while(i < nums.size()-1 && nums[i] == nums[i+1]) i++;
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur_ans;
        
        sort(nums.begin(), nums.end());//NOTE: subset property. not choose back
        
        backtrack_n_ary_tree_not_choose_back(nums, ans, cur_ans);
        return ans;
    }
};
