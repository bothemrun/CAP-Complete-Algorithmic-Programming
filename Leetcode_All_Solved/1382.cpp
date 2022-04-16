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
    vector<int> sorted;
    void inorder(TreeNode* root){
        if(root==nullptr)return;
        inorder(root->left);
        sorted.push_back(root->val);
        inorder(root->right);
    }
    TreeNode* divide_conquer(const vector<int>& sorted, int low, int high){
        if(low > high)return nullptr;
        int mid = low + (high-low)/2;
        TreeNode* n = new TreeNode(sorted[mid]);
        if(low == high)return n;
        
        n->left = divide_conquer(sorted, low, mid-1);
        n->right = divide_conquer(sorted, mid+1, high);
        return n;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        //NOTE: Leetcode 108 proof by even worst case & recursion
        return divide_conquer(sorted, 0, sorted.size()-1);
    }
};
