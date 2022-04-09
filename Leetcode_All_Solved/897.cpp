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
    TreeNode* inorder(TreeNode* root, TreeNode*& rightmost){
        if(root==nullptr)return nullptr;
        
        TreeNode* left_rightmost;
        TreeNode* left_root = inorder(root->left, left_rightmost);
        
        //NOTE: if return root != null, then return rightmost != null
        if(left_root != nullptr)left_rightmost->right = root;
        
        root->left = nullptr;//NOTE
        
        root->right = inorder(root->right, rightmost);
        if(root->right == nullptr)rightmost = root;//NOTE
        
        if(left_root != nullptr)return left_root;
        else return root;
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* rightmost;
        return inorder(root, rightmost);
    }
};
