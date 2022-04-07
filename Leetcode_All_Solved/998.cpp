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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        TreeNode* dummy = new TreeNode((-1), nullptr, root);
        TreeNode* pre = dummy;
        while(pre->right != nullptr && pre->right->val > val)pre = pre->right;
        if(pre == dummy)return new TreeNode(val, root, nullptr);
        if(pre->right == nullptr)
            pre->right = new TreeNode(val);
        else{
            TreeNode* new_node = new TreeNode(val, pre->right, nullptr);
            pre->right = new_node;
        }
        return root;
    }
};
