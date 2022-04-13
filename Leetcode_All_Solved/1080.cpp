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
class Solution {
private:
    int Limit;
    bool postorder(TreeNode* root, int& max_low_sum, int high_sum=0){
        if(!root){
            //max_low_sum dont't care
            return false;
        }
        
        int max_low_sum_l = INT_MIN, max_low_sum_r = INT_MIN;//NOTE: below NOTE
        bool suff_l = postorder(root->left, max_low_sum_l, root->val + high_sum);
        bool suff_r = postorder(root->right, max_low_sum_r, root->val + high_sum);
        
        //NTOE: spent 2 hours here
        if(root->left)max_low_sum = max(max_low_sum, max_low_sum_l);
        if(root->right)max_low_sum = max(max_low_sum, max_low_sum_r);
        if(!root->left && !root->right)max_low_sum = 0;
        max_low_sum += root->val;//NOTE: can't val + INT_MIN, or underflow
        
        if(!suff_l)root->left = nullptr;
        if(!suff_r)root->right = nullptr;
        
        if(max_low_sum + high_sum < Limit)return false;
        else return true;
    }
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        Limit = limit;
        int max_low_sum = INT_MIN;//NOTE
        if(postorder(root, max_low_sum))return root;
        else return nullptr;
    }
};
