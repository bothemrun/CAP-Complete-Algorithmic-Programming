#define num_max 9
class Solution {
private:
    void backtrack_binary_tree(const int& k, const int& n, vector<vector<int>>& ans, vector<int>& cur_ans,  int consider=1, int cur_sum=0){
        if(cur_sum == n && cur_ans.size() == k){
            ans.push_back(cur_ans);
            return;
        }else if(cur_sum > n || consider > num_max) return;
        
        backtrack_binary_tree(k, n, ans, cur_ans,  consider + 1, cur_sum);
        
        cur_ans.push_back(consider);
        backtrack_binary_tree(k, n, ans, cur_ans,  consider + 1, cur_sum + consider);
        cur_ans.pop_back();
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> cur_ans;
        
        backtrack_binary_tree(k, n, ans, cur_ans);
        return ans;
    }
};
