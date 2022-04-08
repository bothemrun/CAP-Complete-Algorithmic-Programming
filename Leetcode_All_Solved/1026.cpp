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
    int max_diff = 0;
    void preorder(TreeNode* root, int path_min, int path_max){
        if(root==nullptr)return;
        path_min = min(path_min, root->val);
        path_max = max(path_max, root->val);
        max_diff = max(max_diff, path_max - path_min);
        preorder(root->left, path_min, path_max);
        preorder(root->right, path_min, path_max);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        preorder(root, root->val, root->val);
        return max_diff;
    }
};
