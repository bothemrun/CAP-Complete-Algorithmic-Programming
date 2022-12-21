//m1
//NOTE: use the template/pattern of tree diameter.
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
    int max_path = 0;
    int tree_diameter(TreeNode* root){
        if(root == nullptr)return 0;

        int l = tree_diameter(root->left);
        if(root->left != nullptr && root->left->val != root->val)
            l = 0;
        int r = tree_diameter(root->right);
        if(root->right != nullptr && root->right->val != root->val)
            r = 0;
        
        max_path = max(max_path, l+r);

        return max(l, r) + 1;
    }
    int longestUnivaluePath(TreeNode* root) {
        tree_diameter(root);
        return max_path;
    }
};
