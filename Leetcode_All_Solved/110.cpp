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
#include<algorithm>
class Solution {
private:
    bool balanced(TreeNode* root, int& max_depth){
        if(root == nullptr){
            max_depth = 0;
            return true;
        }
        
        int l_max_depth, r_max_depth;
        bool ans = balanced(root->left, l_max_depth) && balanced(root->right, r_max_depth);
        max_depth = 1 + max(l_max_depth, r_max_depth);
        return ans && abs(l_max_depth - r_max_depth) <= 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        int max_depth;
        return balanced(root, max_depth);
    }
};
