/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    int lca_path(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& ans){
        if(root == nullptr)return 0;
        int n_path = 0;
        if(root == p || root == q) n_path = 1;
        int l_path = lca_path(root->left, p, q, ans);
        int r_path = lca_path(root->right, p, q, ans);

        if(l_path == 2 || r_path == 2)return 2;//already found lca in subtrees.
        
        n_path += (l_path + r_path);
        if(n_path == 2){
            ans = root; //first time 2, this is the lca
            return 2;
        }
        
        return n_path;//pass up
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans;
        lca_path(root, p, q, ans);
        return ans;
    }
};
