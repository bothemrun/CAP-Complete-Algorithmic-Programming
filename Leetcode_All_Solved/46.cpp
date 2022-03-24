#include<string.h>
class Solution {
private:
    void backtrack(const vector<int>& nums,vector<vector<int>>& ans,const int& n, int cur_used[], vector<int>& cur_ans){
        if(cur_ans.size() == n){
            ans.push_back(cur_ans);
            return;
        }
        
        for(int i=0;i<n;i++)if(cur_used[i] == false){
            cur_used[i] = true;
            cur_ans.push_back(nums[i]);
            backtrack(nums,ans,n, cur_used, cur_ans);
            cur_used[i] = false;
            cur_ans.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        int cur_used[n];//value:0~n-1, need conversion by nums
        memset(cur_used,0,sizeof(cur_used));
        vector<int> cur_ans;
        backtrack(nums,ans,n,cur_used,cur_ans);
        return ans;
    }
};
