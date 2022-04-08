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
    int max_path = 0;
    void preorder(TreeNode* root, int cur_path=0, int last_direction=(-1)){
        if(root==nullptr)return;
        max_path = max(max_path, cur_path);
        if(last_direction == 0){
            preorder(root->left, 1, 0);
            preorder(root->right, cur_path+1, 1);
        }else if(last_direction == 1){
            preorder(root->left, cur_path+1, 0);
            preorder(root->right, 1, 1);
        }else{
            preorder(root->left, 1, 0);
            preorder(root->right, 1, 1);
        }
    }
public:
    int longestZigZag(TreeNode* root) {
        preorder(root);
        return max_path;
    }
};
