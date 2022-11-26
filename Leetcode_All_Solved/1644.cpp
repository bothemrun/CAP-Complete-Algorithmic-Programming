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
public:
    int count_postorder(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& lca){
        if(root == nullptr)return 0;
        
        int l_count = count_postorder(root->left, p, q, lca);
        int r_count = count_postorder(root->right, p, q, lca);
        if(l_count == 2 || r_count == 2)return 2;
        
        int count = l_count + r_count + (root == p) + (root == q);
        if(count == 2)
            lca = root;
        return count;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* lca;
        if( count_postorder(root, p, q, lca) != 2)return nullptr;
        return lca;
    }
};
