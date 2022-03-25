//m1
#define num_max 9
class Solution {
private:
    void backtrack_n_ary_tree(const int& k, const int& n, vector<vector<int>>& ans, vector<int>& cur_ans,  int cur_sum=0, int begin=1){
        if(cur_sum == n && cur_ans.size() == k){
            ans.push_back(cur_ans);
            return;
        }else if(cur_sum > n) return;
        
        //NOTE: subset property. not choose back
        for(int i=begin;i<=num_max;i++){
            cur_ans.push_back(i);
            backtrack_n_ary_tree(k, n, ans, cur_ans,  cur_sum + i, i + 1);//NOTE: subset property. not choose back
            cur_ans.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> cur_ans;
        
        backtrack_n_ary_tree(k, n, ans, cur_ans);
        return ans;
    }
};
