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
public:
    int max_path_sum = 0;
    int postorder(TreeNode* root){
        if(root == nullptr)return 0;
        int left_max_path = postorder(root->left);
        int right_max_path = postorder(root->right);
        max_path_sum = max(max_path_sum, left_max_path + right_max_path);
        return 1 + max(left_max_path, right_max_path);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        //diameter = path must pass thru 1 subtree root
        postorder(root);
        return max_path_sum;
    }
};
