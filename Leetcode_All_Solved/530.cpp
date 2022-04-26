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
    vector<int> inorder;
    void inorder_tra(TreeNode* root){
        if(root == nullptr)return;
        inorder_tra(root->left);
        inorder.push_back(root->val);
        inorder_tra(root->right);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        inorder_tra(root);
        
        int min_diff = inorder.back() - inorder.front();
        for(int i=0;i<inorder.size()-1;i++)min_diff = min(min_diff, inorder[i+1] - inorder[i] );
        return min_diff;
    }
};
