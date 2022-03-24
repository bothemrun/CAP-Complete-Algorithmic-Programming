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
    void preorder(TreeNode *root, TreeNode *&preorder_pred){
        if(root != nullptr){
            TreeNode *root_left = root->left, *root_right = root->right;//NOTE: crucial
            
            if(preorder_pred != nullptr){
                preorder_pred->left = nullptr;
                preorder_pred->right = root;
            }
            preorder_pred = root;//visit
            
            //NOTE:crucial: preorder(root->left, preorder_pred);
            preorder(root_left, preorder_pred);
            preorder(root_right, preorder_pred);
        }
    }
public:
    void flatten(TreeNode* root) {
        TreeNode *preorder_pred = nullptr;
        preorder(root,preorder_pred);
    }
};
