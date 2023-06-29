//wrong answer in previous AC submissions.

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
#include<math.h>
#include<algorithm>

class Solution {
public:
    int ans;
    void preorder(TreeNode* root, const double& target){
        if(!root) return;

        double diff1 = abs(root->val - target);
        double diff2 = abs(ans - target);
        if(diff1 < diff2) ans = root->val;
        else if(diff1 == diff2) ans = min(ans, root->val);
        
        preorder(root->left, target);
        preorder(root->right, target);
    }
    int closestValue(TreeNode* root, double target) {
        ans = root->val;
        preorder(root, target);
        return ans;
    }
};
