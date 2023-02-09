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
    bool preorder_fork(TreeNode* root, const vector<int>& arr, int i=0){
        //NOTE: real leaf
        //NOTE: a node with only 1 child doesn't satisfy this.
        
        //NOTE: arr.size() >= 1
        if(root == nullptr)return false;

        if(root->val != arr.at(i))
            return false;

        if(i == arr.size()-1 && 
        (root->left==nullptr && root->right==nullptr) )
            return true;
        
        if(i == arr.size()-1 || 
        (root->left==nullptr && root->right==nullptr) )
            return false;
        
        return preorder_fork(root->left, arr, i+1) ||
        preorder_fork(root->right, arr, i+1);
    }
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        return preorder_fork(root, arr);
    }
};
