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
#include<algorithm>
class Solution {
private:
    int preorder(TreeNode* root, const int& min_val){
        if(root == nullptr)return (-1);
        if(root->val != min_val)return root->val;
        if(root->left == nullptr)return (-1);
        int left = preorder(root->left, min_val);
        int right = preorder(root->right, min_val);
        if(left == (-1) && right == (-1))return (-1);
        if(left == (-1))return right;
        if(right == (-1))return left;
        return min(left, right);
    }
public:
    int findSecondMinimumValue(TreeNode* root) {
        return preorder(root, root->val);
    }
};
