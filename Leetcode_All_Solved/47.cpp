#include<unordered_set>
class Solution {
private:
    void backtrack(const vector<int>& nums, vector<vector<int>>& ans, vector<int>& cur_ans, vector<bool>& cur_used){
        if(cur_ans.size() == nums.size()){
            ans.push_back(cur_ans);
            return;
        }
        
        unordered_set<int> neighbor_deduplicate;
        for(int i=0;i<nums.size();i++)if(cur_used[i] == false){
            if(neighbor_deduplicate.find(nums[i]) != neighbor_deduplicate.end()) continue;
            else neighbor_deduplicate.insert(nums[i]);
            //NOTE: neighbor deduplicate by hash set
            
            cur_ans.push_back(nums[i]);
            cur_used[i] = true;
            backtrack(nums, ans, cur_ans, cur_used);
            //NOTE: backtrack
            cur_ans.pop_back();
            cur_used[i] = false;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur_ans;
        
        vector<bool> cur_used (nums.size(), false);
        
        backtrack(nums, ans, cur_ans, cur_used);
        return ans;
    }
};
