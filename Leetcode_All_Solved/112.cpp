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
    bool pathSum(TreeNode* root,const int& targetSum,int currentSum){
        if(root->left == nullptr && root->right == nullptr){
            if(currentSum + root->val == targetSum) return true;
            else return false;
        }
        bool ans = false;
        if(root->left != nullptr) ans |= pathSum(root->left,targetSum,currentSum+root->val);
        if(root->right != nullptr) ans |= pathSum(root->right,targetSum, currentSum+root->val);
        return ans;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return false;
        int currentSum = 0;
        return pathSum(root,targetSum,currentSum);
    }
};
