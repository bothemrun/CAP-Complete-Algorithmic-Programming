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
#include<stdlib.h>
class Solution {
public:
    int tilt_sum = 0;
    int postorder(TreeNode *root){
        if(root == nullptr)return 0;
        int sum_l = postorder(root->left);
        int sum_r = postorder(root->right);
        tilt_sum += abs(sum_l - sum_r);
        return root->val + sum_l + sum_r;
    }
    int findTilt(TreeNode* root) {
        postorder(root);
        return tilt_sum;
    }
};
