//m1
#include<algorithm>
class Solution {
private:
    void backtrack_n_ary_tree_not_choose_back(const vector<int>& candidates, const int& target, vector<vector<int>>& ans, vector<int>& cur_ans,  int cur_sum=0, int begin=0){
        if(cur_sum == target){
            ans.push_back(cur_ans);
            return;
        }else if(cur_sum > target)return;
        
        for(int i=begin;i<candidates.size();i++){
            cur_ans.push_back(candidates[i]);
            backtrack_n_ary_tree_not_choose_back(candidates, target, ans, cur_ans,  cur_sum + candidates[i], i + 1);
            //NOTE: subset property. not choose back
            cur_ans.pop_back();
            
            //NOTE: neighbor de-duplicate
            while(i < candidates.size()-1 && candidates[i] == candidates[i+1]) i++;
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur_ans;
        
        sort(candidates.begin(), candidates.end());//NOTE: subset property. not choose back
        
        backtrack_n_ary_tree_not_choose_back(candidates, target, ans, cur_ans);
        return ans;
    }
};
