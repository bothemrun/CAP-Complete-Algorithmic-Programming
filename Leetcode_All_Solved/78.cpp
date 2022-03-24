class Solution {
private:
    void backtrack(const vector<int>& nums, const int& n, vector<vector<int>>& ans, vector<int>& cur_ans, int considered){
        if(considered == n){
            ans.push_back(cur_ans);
            return;
        }
        
        backtrack(nums,n,ans, cur_ans, considered+1);
        cur_ans.push_back(nums[considered]);
        backtrack(nums,n,ans, cur_ans, considered+1);
        cur_ans.pop_back();//NOTE: important
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur_ans;
        int n = nums.size();
        backtrack(nums,n, ans, cur_ans, 0);
        return ans;
    }
};
