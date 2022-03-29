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
    bool prune_children(TreeNode* root){
        if(root == nullptr)return false;
        bool l_has1 = prune_children(root->left);
        bool r_has1 = prune_children(root->right);
        if(l_has1 == false)root->left = nullptr;
        if(r_has1 == false)root->right = nullptr;
        return l_has1 || r_has1 || root->val == 1;
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        TreeNode* dummy = new TreeNode(2, root, nullptr);
        prune_children(dummy);
        return dummy->left;//NOTE: can be nullptr
    }
};
