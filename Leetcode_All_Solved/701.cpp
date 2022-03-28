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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* new_node = new TreeNode(val);
        if(root == nullptr)return new_node;
        
        TreeNode *pre_node, *cur_node = root;
        bool right_child;
        while(cur_node != nullptr){
            pre_node = cur_node;
            if(cur_node->val < val){
                cur_node = cur_node->right;
                right_child = true;
            }else{ 
                cur_node = cur_node->left;
                right_child = false;
            }
        }
        
        if(right_child)pre_node->right = new_node;
        else pre_node->left = new_node;
        return root;
    }
};
