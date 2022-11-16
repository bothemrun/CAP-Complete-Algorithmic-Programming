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
struct subtree{
    int sum;
    int n;
};
class Solution {
public:
    double max_av = 0;
    struct subtree postorder(TreeNode* root){
        if(root == nullptr){
            struct subtree sub = {0, 0};
            return sub;
        }
        
        struct subtree sub_l = postorder(root->left);
        struct subtree sub_r = postorder(root->right);
        
        struct subtree sub = {sub_l.sum + sub_r.sum + root->val, sub_l.n + sub_r.n + 1};
        max_av = max(max_av, (double)sub.sum / (double)sub.n );
        return sub;
    }
    double maximumAverageSubtree(TreeNode* root) {
        postorder(root);
        return max_av;
    }
};
