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
private:
    int choose_left_or_right(TreeNode* root, int& global_max){
        //return: max univalue length s.t. the upper nodes may connect to it
        if(root == nullptr)return 0;
        
        int l_connect_len = choose_left_or_right(root->left, global_max);
        int r_connect_len = choose_left_or_right(root->right, global_max);
        
        //may not connect with upper nodes
        int root_self_connect_len = 0;
        if(root->left != nullptr && root->left->val == root->val)root_self_connect_len += 1 + l_connect_len;
        if(root->right != nullptr && root->right->val == root->val)root_self_connect_len += 1 + r_connect_len;
        global_max = max(global_max, root_self_connect_len);
        
        //may connect with upper nodes
        int root_connect_len = 0;//only this root itself
        if(root->left != nullptr && root->left->val == root->val) root_connect_len = max(root_connect_len, 1+l_connect_len);
        if(root->right != nullptr && root->right->val == root->val) root_connect_len = max(root_connect_len, 1+r_connect_len);
        return root_connect_len;//this already considered in case of global_max
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        int global_max = 0;//int global_max;
        choose_left_or_right(root, global_max);
        return global_max;
    }
};
