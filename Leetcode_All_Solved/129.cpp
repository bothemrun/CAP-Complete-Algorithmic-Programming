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
    void sum_path(TreeNode* root,int& ans, int cur_ans){
        cur_ans = cur_ans*10+root->val;
        if(root->left == nullptr && root->right == nullptr){
            ans += cur_ans;
            return;
        }
        
        if(root->left != nullptr) sum_path(root->left,ans,cur_ans);
        if(root->right != nullptr) sum_path(root->right,ans,cur_ans);
    }
public:
    int sumNumbers(TreeNode* root) {
        int ans = 0, cur_ans = 0;
        sum_path(root,ans,cur_ans);
        return ans;
    }
};
