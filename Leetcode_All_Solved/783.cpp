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
#include<limits.h>
#include<stdlib.h>
class Solution {
public:
    int min_diff = INT_MAX;
    void postorder(TreeNode* root, int& submin, int& submax){
        if(root == nullptr){
            submin = INT_MAX;
            submax = INT_MIN;
            return;
        }

        int submin_l, submax_l;
        int submin_r, submax_r;
        postorder(root->left, submin_l, submax_l);
        postorder(root->right, submin_r, submax_r);

        if(root->left)
            min_diff = min(min_diff, abs(root->val - submax_l) );
        if(root->right)
            min_diff = min(min_diff, abs(root->val - submin_r) );
        
        submin = min(root->val, submin_l);
        submax = max(root->val, submax_r);
    }
    int minDiffInBST(TreeNode* root) {
        int submin, submax;
        postorder(root, submin, submax);
        return min_diff;
    }
};
