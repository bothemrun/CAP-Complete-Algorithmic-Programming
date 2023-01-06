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
public:
    int max_bst = 0;

    bool minmax_post(TreeNode* root, int& sub_min, int& sub_max, int& sub_cnt){
        if(root == nullptr){
            sub_min = INT_MAX;
            sub_max = INT_MIN;
            sub_cnt = 0;
            return true;
        }

        int l_min, l_max, l_cnt;
        int r_min, r_max, r_cnt;
        
        bool l = minmax_post(root->left, l_min, l_max, l_cnt);

        /*bool r = false;
        if(l == true) r = minmax_post(root->right, r_min, r_max, r_cnt);*/
        //NOTE: can' prune
        bool r = minmax_post(root->right, r_min, r_max, r_cnt);

        
        //if false, don't care.
        if( !( l && r && l_max < root->val && root->val < r_min ) ) return false;
        cout << "here\n";

        /*sub_min = l_min;
        sub_max = r_max;*/
        //NOTE:
        sub_min = (l_min==INT_MAX)? root->val:l_min;
        sub_max = (r_max==INT_MIN)? root->val:r_max;

        sub_cnt = l_cnt + r_cnt + 1;
        max_bst = max(max_bst, sub_cnt);
        return true;
    }

    int largestBSTSubtree(TreeNode* root) {
        int sub_min, sub_max, sub_cnt;
        minmax_post(root, sub_min, sub_max, sub_cnt);
        return max_bst;
    }
};
