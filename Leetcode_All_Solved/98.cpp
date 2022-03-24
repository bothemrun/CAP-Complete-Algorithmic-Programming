#include<limits.h>
#include<algorithm>
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
    bool valid_bst(TreeNode* root, long long& submin, long long& submax){
        if(root == nullptr){
            submin = LLONG_MAX;
            submax = LLONG_MIN;
            return true;
        }
        
        long long left_submax;
        long long left_submin;
        bool left = valid_bst(root->left, left_submin, left_submax);
        long long right_submax;
        long long right_submin;
        bool right = valid_bst(root->right, right_submin, right_submax);
        
        //subtrees might be nullptr
        submax = max((long long)root->val, right_submax);
        submin = min(left_submin, (long long)root->val);
        
        return left && right && left_submax < root->val && root->val < right_submin;
        //overflow: return left && right && ( (left_submax==INT_MIN)?true:(left_submax < root->val) ) && ( (right_submin==INT_MAX)?true:(root->val < right_submin) );
        //WA: return left && right && (left_submax==INT_MIN)?true:(left_submax < root->val) && (right_submin==INT_MAX)?true:(root->val < right_submin);
    }
public:
    bool isValidBST(TreeNode* root) {
        long long submin = LLONG_MAX;
        long long submax = LLONG_MIN;
        return valid_bst(root, submin, submax);
    }
};
