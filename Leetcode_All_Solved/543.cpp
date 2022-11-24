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
    int subtree_max_depth_postorder(TreeNode* root, int& max_diameter){
        if(root == nullptr)return 0;
        
        int l_subtree_max_depth = subtree_max_depth_postorder(root->left, max_diameter);
        int r_subtree_max_depth = subtree_max_depth_postorder(root->right, max_diameter);
        
        max_diameter = max(max_diameter, l_subtree_max_depth + r_subtree_max_depth);
        
        return max(l_subtree_max_depth, r_subtree_max_depth) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int max_diameter = 0;
        subtree_max_depth_postorder(root, max_diameter);
        return max_diameter;
    }
};
