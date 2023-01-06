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
#include<assert.h>
class Solution {
public:
    vector<int> boundary;
    
    void left_boundary(TreeNode* root){
        assert(root != nullptr);
        if(root->left == nullptr && root->right == nullptr)return;

        boundary.push_back(root->val);
        if(root->left) left_boundary(root->left);
        else left_boundary(root->right);
    }

    void leaves(TreeNode* root){
        if(root == nullptr)return;
        if(root->left == nullptr && root->right == nullptr){
            boundary.push_back(root->val);
            return;
        }

        leaves(root->left);
        leaves(root->right);
    }

    void right_boundary(TreeNode* root){
        assert(root != nullptr);
        if(root->left == nullptr && root->right == nullptr)return;

        if(root->right) right_boundary(root->right);
        else right_boundary(root->left);

        boundary.push_back(root->val);
    }

    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        boundary.push_back(root->val);
        
        if(root->left != nullptr)left_boundary(root->left);
        
        if(root->left || root->right) leaves(root);
        
        if(root->right != nullptr)right_boundary(root->right);
        
        return boundary;
    }
};



