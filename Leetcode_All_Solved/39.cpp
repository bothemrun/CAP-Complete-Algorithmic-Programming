class Solution {
private:
    void backtrack(const vector<int>& candidates, const int& target, vector<vector<int>>& ans, vector<int>& cur_ans, int cur_sum=0, int begin=0){
        if(cur_sum > target)return;
        else if(cur_sum == target){
            ans.push_back(cur_ans);
            return;
        }
   
        //NOTE: begin: de-duplicate, not choose back
        for(int i=begin;i<candidates.size();i++){
            cur_ans.push_back(candidates[i]);
            backtrack(candidates, target, ans, cur_ans, cur_sum + candidates[i], i);
            cur_ans.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur_ans;
        
        backtrack(candidates, target, ans, cur_ans);
        return ans;
    }
};
