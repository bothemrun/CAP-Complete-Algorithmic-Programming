//m1
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
    bool found_p = false, found_q = false;
    TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == nullptr)return nullptr;
        
        if(root == p){
            found_p = true;
        }
        if(root == q){
            found_q = true;
        }
        
        TreeNode* left = LCA(root->left, p, q);
        TreeNode* right = LCA(root->right, p, q);
        int count = (left!=nullptr) + (right!=nullptr) + (root==p) + (root==q);
        if(count == 2)return root;
        if(count == 0)return nullptr;
        //now count == 1
        if(root == p || root == q)return root;
        return (left == nullptr)? right:left;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* lca = LCA(root, p, q);
        if(!(found_p && found_q))return nullptr;
        return lca;
    }
};
