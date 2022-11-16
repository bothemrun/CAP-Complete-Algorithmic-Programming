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
    void preorder(vector<int>& lonely, TreeNode* root){
        if(root == nullptr) return;
        
        if(root->left == nullptr && root->right != nullptr) lonely.push_back(root->right->val);
        if(root->right == nullptr && root->left != nullptr) lonely.push_back(root->left->val);
        
        if(root->left != nullptr) preorder(lonely, root->left);
        if(root->right != nullptr) preorder(lonely, root->right);
    }
    vector<int> getLonelyNodes(TreeNode* root) {
        vector<int> lonely;
        preorder(lonely, root);
        return lonely;
    }
};
