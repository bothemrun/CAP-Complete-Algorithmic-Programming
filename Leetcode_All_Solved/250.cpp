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
public:
    int cnt = 0;
    bool univalue_post(TreeNode* r){
        if(r == nullptr)return true;
        if(r->left==nullptr && r->right==nullptr){
            cnt++;
            return true;
        }

        bool uni_l = univalue_post(r->left);
        bool uni_r = univalue_post(r->right);

        bool cond_l = uni_l & ( r->left==nullptr ||
            r->left && r->left->val == r->val );
        bool cond_r = uni_r & ( r->right==nullptr ||
            r->right && r->right->val == r->val );
        if(cond_l & cond_r){
            cnt++;
            return true;
        }else return false;
    }
    int countUnivalSubtrees(TreeNode* root) {
        univalue_post(root);
        return cnt;
    }
};
