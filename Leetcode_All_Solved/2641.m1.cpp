//m1
//don't new new nodes, just in-place.
//don't use hash map
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
#define max_level ((int)1e5 + 1)
class Solution {
public:
    int level2sum[max_level] = {0};
    void dfs_level_sum(TreeNode* root, const int& level=0){
        if(!root)return;
        level2sum[level] += root->val;
        dfs_level_sum(root->left, level+1);
        dfs_level_sum(root->right, level+1);
    }
    void dfs_cousin_inplace(TreeNode* root, const int& sibling_sum, const int& level=0){
        if(!root)return;

        root->val = level2sum[level] - sibling_sum;
        
        int child_sibling_sum = ((root->left)? root->left->val:0) + ((root->right)? root->right->val:0);
        dfs_cousin_inplace(root->left, child_sibling_sum, level+1);
        dfs_cousin_inplace(root->right, child_sibling_sum, level+1);
    }

    TreeNode* replaceValueInTree(TreeNode* root) {
        dfs_level_sum(root);
        dfs_cousin_inplace(root, root->val);
        return root;
    }
};
