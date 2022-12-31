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
    TreeNode* upside_down_bst(TreeNode* root){
        assert(root != nullptr);
        if(root->left == nullptr){
            assert(root->right == nullptr);
            return root;//NOTE: topmost root
        }

        //NOTE: now root->left != nullptr

        TreeNode* topmost_root = upside_down_bst(root->left);
        assert( 
            root->left->left == nullptr &&
            root->left->right == nullptr
        );


        //1. old left node
        root->left->right = root;
        root->left->left = root->right;//NOTE: may be nullptr

        //2. old root
        root->left = nullptr;
        root->right = nullptr;

        return topmost_root;
    }
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if(root == nullptr)return nullptr;
        return upside_down_bst(root);
    }
};
