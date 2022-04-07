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
    void dfs(TreeNode* root, const int& val, const int& depth, int cur_depth=0){
        if(cur_depth + 1 > depth || root == nullptr)return;
        if(cur_depth + 1 == depth){
            TreeNode* left = new TreeNode(val, root->left, nullptr);
            TreeNode* right = new TreeNode(val, nullptr, root->right);
            root->left = left;
            root->right = right;
            return;
        }
        dfs(root->left, val, depth, cur_depth+1);
        dfs(root->right, val, depth, cur_depth+1);
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        TreeNode* dummy = new TreeNode((-99999), root, nullptr);
        dfs(dummy, val, depth);
        return dummy->left;
    }
};
