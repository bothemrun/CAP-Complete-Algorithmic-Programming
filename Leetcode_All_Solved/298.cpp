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
    void preorder(TreeNode* root, const int& parent_val, int path=0){
        if(root == nullptr)return;

        if(root->val == parent_val + 1){
            path++;
        }else{
            path = 1;
        }
        max_path = max(max_path, path);

        preorder(root->left, root->val, path);
        preorder(root->right, root->val, path);
    }
    int longestConsecutive(TreeNode* root) {
        preorder(root, root->val - 1);
        return max_path;
    }
};
