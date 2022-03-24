//m1
class Solution {
private:
    void backtrack_n_ary(const vector<int>& nums, vector<vector<int>>& ans, vector<int>& cur_ans, int begin){
        ans.push_back(cur_ans);
        
        for(int i=begin;i<nums.size();i++){
            cur_ans.push_back(nums[i]);
            backtrack_n_ary(nums, ans, cur_ans, i + 1);//NOTE: not choosing back
            cur_ans.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur_ans;
        
        backtrack_n_ary(nums, ans, cur_ans, 0);
        return ans;
    }
};
