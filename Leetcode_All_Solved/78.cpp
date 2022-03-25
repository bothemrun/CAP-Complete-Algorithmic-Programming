class Solution {
private:
    void backtrack_binary_tree(const vector<int>& nums, vector<vector<int>>& ans, vector<int>& cur_ans, int considered=0){
        if(considered == nums.size()){
            ans.push_back(cur_ans);
            return;
        }
        
        backtrack_binary_tree(nums, ans, cur_ans, considered + 1);
        
        cur_ans.push_back(nums[considered]);
        backtrack_binary_tree(nums, ans, cur_ans, considered + 1);
        cur_ans.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur_ans;
        
        backtrack_binary_tree(nums, ans, cur_ans);
        return ans;
    }
};
