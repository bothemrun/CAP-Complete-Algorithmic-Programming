#include<unordered_set>
class Solution {
private:
    void backtrack(const vector<int>& nums, vector<vector<int>>& ans, vector<int>& cur_ans, vector<bool>& cur_used){
        if(cur_ans.size() == nums.size()){
            ans.push_back(cur_ans);
            return;
        }
        
        unordered_set<int> enumerated_in_this_spot;
        for(int i=0;i<nums.size();i++)if(cur_used[i] == false){
            //NOTE: deduplicate
            if(enumerated_in_this_spot.find(nums[i]) != enumerated_in_this_spot.end()) continue;
            else enumerated_in_this_spot.insert(nums[i]);
            
            cur_used[i] = true;
            cur_ans.push_back(nums[i]);
            backtrack(nums,ans,cur_ans, cur_used);
            //NOTE: backtrack
            cur_used[i] = false;
            cur_ans.pop_back();
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur_ans;
        vector<bool> cur_used (nums.size(), false);
        
        backtrack(nums,ans,cur_ans, cur_used);
        return ans;
    }
};
