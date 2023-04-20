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
#include<unordered_map>
class Solution {
public:
    unordered_map<int,int> level2sum;
    void dfs_level_sum(TreeNode* root, const int& level){
        if(!root)return;

        level2sum[level] += root->val;

        dfs_level_sum(root->left, level+1);
        dfs_level_sum(root->right, level+1);
    }

    TreeNode* dfs_cousin(TreeNode* root, TreeNode* parent, const int& level){
        if(!root)return nullptr;

        int val = level2sum[level];
        if(parent) val -= ((parent->left)? parent->left->val:0) + ((parent->right)? parent->right->val:0);
        else val -= root->val;

        TreeNode* new_root = new TreeNode(val);
        new_root->left = dfs_cousin(root->left, root, level+1);
        new_root->right = dfs_cousin(root->right, root, level+1);
        
        return new_root;
    }

    TreeNode* replaceValueInTree(TreeNode* root) {
        dfs_level_sum(root, 0);

        return dfs_cousin(root, nullptr, 0);
    }
};
