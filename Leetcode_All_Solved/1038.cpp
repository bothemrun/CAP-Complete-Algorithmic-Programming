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
    int cur_sum = 0;
    void reverse_inorder_sum(TreeNode* root){
        //NOTE: right root left order traversal
        if(root == nullptr)return;
        reverse_inorder_sum(root->right);
        int old_root_val = root->val;
        root->val += cur_sum;
        cur_sum += old_root_val;
        reverse_inorder_sum(root->left);
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        reverse_inorder_sum(root);
        return root;
    }
};
