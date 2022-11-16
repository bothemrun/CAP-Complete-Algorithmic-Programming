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
    vector<vector<int>> leaves;
    int height_postorder(TreeNode* root){
        if(root == nullptr)return 0;
        
        int height_l = height_postorder(root->left);
        int height_r = height_postorder(root->right);
        int height = max(height_l, height_r);
        
        if(height >= leaves.size())
            leaves.push_back( vector<int>({root->val}) );
        else leaves.at(height).push_back(root->val);
        
        return height + 1;
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        height_postorder(root);
        return leaves;
    }
};
