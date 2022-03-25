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
    int lca_path_prune(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& ans){
        if(root == nullptr)return 0;
        
        int n_path = 0;
        if(root == p || root == q)n_path = 1;
        
        int l_path = 0, r_path = 0;
        //prune
        if(!(root->val < p->val)) l_path = lca_path_prune(root->left, p, q, ans);
        if(!(q->val < root->val)) r_path = lca_path_prune(root->right, p, q, ans);
        
        if(l_path == 2 || r_path == 2)return 2;//already found lca in subtrees
        
        n_path += (l_path + r_path);
        if(n_path == 2){
            //fist node with path=2(this) is the lca
            ans = root;
            return 2;
        }
        
        return n_path;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans;
        if(p->val > q->val){
            TreeNode* tmp = p;
            p = q;
            q = tmp;
        }
        lca_path_prune(root, p, q, ans);
        return ans;
    }
};
