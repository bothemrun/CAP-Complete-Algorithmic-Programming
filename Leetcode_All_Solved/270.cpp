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
//#include<stdlib.h> //int abs()
#include<math.h> //float abs()
class Solution {
public:
    void preorder(double& min_diff, int& closest, TreeNode* root, const double& target){
        if(root == nullptr)return;
        
        if( abs(target - (double)root->val) < min_diff){
            min_diff = abs(target -(double)root->val);
            closest = root->val;
        }
        
        preorder(min_diff, closest, root->left, target);
        preorder(min_diff, closest, root->right, target);
    }
    int closestValue(TreeNode* root, double target) {
        double min_diff = abs(target - (double)root->val);;
        int closest = root->val; //root != nullptr
        preorder(min_diff, closest, root, target);
        return closest;
    }
};
