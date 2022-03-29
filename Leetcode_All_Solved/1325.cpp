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
    TreeNode* prune_leaves(TreeNode* root, const int& target){
        if(root == nullptr)return nullptr;
        //postorder
        root->left = prune_leaves(root->left, target);
        root->right = prune_leaves(root->right, target);
        if(root->left == nullptr && root->right == nullptr && root->val == target)return nullptr;
        else return root;
    }
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        //the process can proceed to the root.
        return prune_leaves(root, target);
    }
};
