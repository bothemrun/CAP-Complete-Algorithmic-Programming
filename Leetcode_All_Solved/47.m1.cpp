//m1
#include<algorithm>
class Solution {
private:
    void backtrack(const vector<int>& nums, vector<vector<int>>& ans, vector<int>& cur_ans, vector<bool>& cur_used){
        if(cur_ans.size() == nums.size()){
            ans.push_back(cur_ans);
            return;
        }
        
        for(int i=0;i<nums.size();i++)if(cur_used[i] == false){
            cur_ans.push_back(nums[i]);
            cur_used[i] = true;
            backtrack(nums, ans, cur_ans, cur_used);
            //NOTE: backtrack
            cur_ans.pop_back();
            cur_used[i] = false;
            
            while(i < nums.size()-1 && nums[i] == nums[i+1]) i++;//NOTE: de-duplicate in this spot
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur_ans;
        
        vector<bool> cur_used (nums.size(), false);
        
        sort(nums.begin(), nums.end());//NOTE: deduplicate
        
        backtrack(nums, ans, cur_ans, cur_used);
        return ans;
    }
};
