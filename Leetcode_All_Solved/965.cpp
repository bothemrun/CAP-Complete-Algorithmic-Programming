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
public:
    bool uni_tree(TreeNode* root, const int& val){
        if(root == nullptr)return true;
        if(root->val != val)return false;
        return uni_tree(root->left, val) && uni_tree(root->right, val);
    }
    bool isUnivalTree(TreeNode* root) {
        return uni_tree(root, root->val);
    }
};
