#include<algorithm>
class Solution {
private:
    void backtrack_n_ary_tree_not_choose_back(const vector<int>& nums, vector<vector<int>>& ans, vector<int>& cur_ans,  int begin=0){
        ans.push_back(cur_ans);
        
        unordered_set<int> not_neighbor_dup_in_this_spot;
        //NOTE: subset property. not choose back
        for(int i=begin;i<nums.size();i++){
            if(not_neighbor_dup_in_this_spot.find(nums[i]) != not_neighbor_dup_in_this_spot.end()) continue;
            else not_neighbor_dup_in_this_spot.insert(nums[i]);
            //NOTE: neighbor deduplicate, in this spot
            
            cur_ans.push_back(nums[i]);
            backtrack_n_ary_tree_not_choose_back(nums, ans, cur_ans, i + 1);//NOTE: subset property. not choose back
            cur_ans.pop_back();
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
