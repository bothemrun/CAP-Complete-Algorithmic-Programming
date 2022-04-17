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
    TreeNode* search(TreeNode* root, const int& key, TreeNode*& parent, int& left_right){
        if(root == nullptr)return nullptr;
        if(root->val == key)return root;
        
        //NOTE:
        parent = root;
        if(root->val > key){
            left_right = 0;
            return search(root->left, key, parent, left_right);
        }else{
            left_right = 1;
            return search(root->right, key, parent, left_right);
        }
    }
    
    inline TreeNode* smallest(TreeNode* node, TreeNode*& parent, int& left_right){
        //node != null
        while(node->left != nullptr){
            parent = node;
            left_right = 0;
            node = node->left;
        }
        return node;
    }
    inline TreeNode* largest(TreeNode* node, TreeNode*& parent, int& left_right){
        //node != null
        while(node->right != nullptr){
            parent = node;
            left_right = 1;
            node = node->right;
        }
        return node;
    }
    void deletion(TreeNode* key_n, TreeNode* parent, int left_right){
        if(key_n->left == nullptr && key_n->right == nullptr){
            if(left_right == 0)parent->left = nullptr;
            else parent->right = nullptr;
        }else if(key_n->left == nullptr){//right subtree
            TreeNode* parent_tmp = key_n;
            int left_right_tmp = 1;
            TreeNode* next_del = smallest(key_n->right, parent_tmp, left_right_tmp);
            key_n->val = next_del->val;
            deletion(next_del, parent_tmp, left_right_tmp);
        }else{//left subtree
            TreeNode* parent_tmp = key_n;
            int left_right_tmp = 0;
            TreeNode* next_del = largest(key_n->left, parent_tmp, left_right_tmp);
            key_n->val = next_del->val;
            deletion(next_del, parent_tmp, left_right_tmp);
        }
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* dummy = new TreeNode(INT_MIN, root, nullptr);
        TreeNode* parent = dummy;
        int left_right = 0;
        TreeNode* key_n = search(root, key, parent, left_right);
        if(key_n == nullptr)return root;
        
        deletion(key_n, parent, left_right);
        return dummy->left;
    }
};
