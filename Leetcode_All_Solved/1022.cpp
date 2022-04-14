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
    int postorder(TreeNode* root, int high_val=0){
        if(root->left==nullptr && root->right==nullptr){
            return root->val + 2*high_val;
        }
        
        int low_sum = 0;
        if(root->left)low_sum += postorder(root->left, root->val + 2*high_val);
        if(root->right)low_sum += postorder(root->right, root->val + 2*high_val);
        return low_sum;
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        return postorder(root);
    }
};
