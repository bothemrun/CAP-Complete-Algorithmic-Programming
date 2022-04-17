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
#include<stdlib.h>
class Solution {
private:
    int postorder(TreeNode* root, int& total_flow){
        if(root==nullptr)return 0;
        int left = postorder(root->left, total_flow);
        int right = postorder(root->right, total_flow);
        
        int balance = root->val + left + right - 1;
        total_flow += abs(balance);
        return balance;
    }
public:
    int distributeCoins(TreeNode* root) {
        int total_flow = 0;
        postorder(root, total_flow);
        return total_flow;
    }
};
