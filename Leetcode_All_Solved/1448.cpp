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
    int ans = 0;
    void preorder(TreeNode* root, int path_max=INT_MIN){
        if(root==nullptr)return;
        if(root->val >= path_max){
            ans++;
            path_max = root->val;
        }
        preorder(root->left, path_max);
        preorder(root->right, path_max);
    }
public:
    int goodNodes(TreeNode* root) {
        preorder(root);
        return ans;
    }
};
