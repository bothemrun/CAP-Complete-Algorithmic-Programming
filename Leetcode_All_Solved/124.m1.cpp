//m1
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
public:
    int max_path_sum = INT_MIN;
    int max_to_root_path_postorder(TreeNode* root){
        if(root == nullptr)return 0;//NOTE
        
        int l = max_to_root_path_postorder(root->left);
        int r = max_to_root_path_postorder(root->right);

        //NOTE: cutoff
        l = max(0, l);
        r = max(0, r);

        max_path_sum = max(max_path_sum, root->val + l + r);
        //NOTE: l / r is 0 if nullptr

        return root->val + max(l, r);
    }
    int maxPathSum(TreeNode* root) {
        max_to_root_path_postorder(root);
        return max_path_sum;
    }
};
