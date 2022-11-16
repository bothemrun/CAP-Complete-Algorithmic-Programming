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
class Solution {
public:
    int cnt = 0;
    long long postorder(TreeNode* root){
        if(root == nullptr)return 0;
        
        long long left = postorder(root->left);
        long long right = postorder(root->right);
        if(left + right == root->val)cnt++;
        
        return left + right + root->val;
    }
    int equalToDescendants(TreeNode* root) {
        postorder(root);
        return cnt;
    }
};
