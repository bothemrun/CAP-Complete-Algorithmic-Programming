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
#include<utility>//pair
class Solution {
public:
    pair<int,int> rob_postorder(TreeNode* root){
        if(root == nullptr)return pair<int,int>({0, 0});
        
        pair<int,int> l = rob_postorder(root->left);
        pair<int,int> r = rob_postorder(root->right);
        return pair<int,int>( { max(l.first, l.second) + max(r.first, r.second) , root->val + l.first + r.first} );
    }
    int rob(TreeNode* root) {
        pair<int,int> ret = rob_postorder(root);//.first: not robbed, .second: robbed
        return max(ret.first, ret.second);
    }
};
