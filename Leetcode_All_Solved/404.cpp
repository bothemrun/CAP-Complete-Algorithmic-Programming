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
    int preorder(TreeNode* root, bool left_node=false){
        if(root == nullptr)return 0;
        
        if(root->left == nullptr && root->right == nullptr && left_node == true)return root->val;
        return preorder(root->left, true) + preorder(root->right);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return preorder(root);
    }
};
