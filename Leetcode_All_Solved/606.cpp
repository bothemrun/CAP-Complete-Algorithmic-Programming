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
#include<string>
class Solution {
private:
    string preorder(TreeNode* root){
        if(root==nullptr)return "";
        string ans = to_string(root->val);
        string left = preorder(root->left);
        string right = preorder(root->right);
        if(left == "" && right != "")return ans + "()" + "(" + right + ")";
        
        if(left != "")ans += "(" + left + ")";
        if(right != "")ans += "(" + right + ")";
        return ans;
    }
public:
    string tree2str(TreeNode* root) {
        return preorder(root);
    }
};
