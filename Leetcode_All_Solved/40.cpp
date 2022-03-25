#include<algorithm>
class Solution {
private:
    void backtrack_n_ary_tree_not_choose_back(const vector<int>& candidates, const int& target, vector<vector<int>>& ans, vector<int>& cur_ans,  int begin=0, int cur_sum=0){
        if(cur_sum > target) return;
        else if(cur_sum == target){
            ans.push_back(cur_ans);
            return;
        }
        
        //NOTE: neighbor deduplidate in this spot
        unordered_set<int> not_neighbor_dup_in_this_spot;
        //NOTE: subset property. not choose back
        for(int i=begin;i<candidates.size();i++){
            if(not_neighbor_dup_in_this_spot.find(candidates[i]) != not_neighbor_dup_in_this_spot.end()) continue;
            else not_neighbor_dup_in_this_spot.insert(candidates[i]);
            //NOTE: neighbor deduplidate in this spot
            
            cur_ans.push_back(candidates[i]);
            backtrack_n_ary_tree_not_choose_back(candidates, target, ans, cur_ans,  i + 1, cur_sum + candidates[i]);//NOTE: subset property. not choose back
            cur_ans.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur_ans;
        
        //NOTE: subset property. not choose back.
        sort(candidates.begin(), candidates.end());
        
        backtrack_n_ary_tree_not_choose_back(candidates, target, ans, cur_ans);
        return ans;
    }
};
