/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void dfs(TreeNode* root,const int& targetSum, vector<vector<int>>& ans, int cur_sum, vector<int>& cur_ans){
        cur_sum += root->val;
        cur_ans.push_back(root->val);
        
        if(root->left == nullptr && root->right == nullptr){
            if(cur_sum == targetSum) ans.push_back(cur_ans);
            cur_ans.pop_back();
            return;
        }
        
        if(root->left != nullptr) dfs(root->left,targetSum, ans, cur_sum, cur_ans);
        if(root->right != nullptr) dfs(root->right,targetSum, ans, cur_sum, cur_ans);
        
        cur_ans.pop_back();
        return;
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        
        int cur_sum = 0;
        vector<int> cur_ans;
        dfs(root,targetSum, ans, cur_sum, cur_ans);
        return ans;
    }
};
