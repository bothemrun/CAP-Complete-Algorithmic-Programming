#include<algorithm>
#include<string.h>
#include<unordered_set>
class Solution {
private:
    void backtrack(const vector<int>& nums, const int& n, vector<vector<int>>& ans, bool cur_used[], vector<int>& cur_ans){
        if(cur_ans.size() == n){
            ans.push_back(cur_ans);
            return;
        }
        
        unordered_set<int> used_in_this_spot;
        for(int i=0;i<n;i++)if(cur_used[i] == false){
            //NOTE: deduplicate
            if(used_in_this_spot.find(nums[i]) != used_in_this_spot.end())continue;
            else used_in_this_spot.insert(nums[i]);
            
            cur_used[i] = true;
            cur_ans.push_back(nums[i]);
            backtrack(nums,n,ans,cur_used,cur_ans);
            cur_used[i] = false;
            cur_ans.pop_back();
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end());//NOTE: deduplicate
        
        vector<vector<int>> ans;
        
        bool cur_used[n];
        memset(cur_used,0,sizeof(cur_used));
        vector<int> cur_ans;
        
        backtrack(nums,n,ans,cur_used,cur_ans);
        return ans;
    }
};
