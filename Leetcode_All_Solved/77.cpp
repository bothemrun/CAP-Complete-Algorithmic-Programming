class Solution {
private:
    void backtrack(const int& n,const int& k,vector<vector<int>>& ans, vector<int>& cur_ans){
        if(cur_ans.size() == k){
            ans.push_back(cur_ans);
            return;
        }
        
        int start = (cur_ans.size() == 0)? 1:(cur_ans.back()+1);
        for(int i=start;i<=n;i++){
            cur_ans.push_back(i);
            backtrack(n,k,ans,cur_ans);
            cur_ans.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> cur_ans;
        backtrack(n,k,ans,cur_ans);
        return ans;
    }
};
