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
    int Low, High;
    inline bool in(const TreeNode* node){
        return Low <= node->val && node->val <= High;
    }
    TreeNode* trim_bst(TreeNode* root){
        if(root == nullptr)return nullptr;
        //root->val in 1 of 3 intervals
        if(in(root)){
            root->left = trim_bst(root->left);
            root->right = trim_bst(root->right);
            return root;
        }else if(root->val < Low)return trim_bst(root->right);
        else return trim_bst(root->left);
    }
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        Low = low, High = high;
        return trim_bst(root);
    }
};
