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
#include<limits.h>
class Solution {
private:
    int inorder(TreeNode *root, int &idx_inorder, const int &k){
        if(root != nullptr){
            int left = inorder(root->left, idx_inorder, k);
            if(left != INT_MIN)return left;
            
            if(++idx_inorder == k) return root->val;
            
            int right = inorder(root->right, idx_inorder, k);
            if(right != INT_MIN)return right;
            return INT_MIN;
        }
        return INT_MIN;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int idx_inorder = 0;
        return inorder(root, idx_inorder, k);
    }
};
