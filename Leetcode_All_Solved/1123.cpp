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
#include<unordered_set>
class Solution {
private:
    unordered_set<TreeNode*> deepest_leaves;
    int max_level = 0;
    void preorder(TreeNode* root, int level=0){
        if(root==nullptr)return;
        if(level > max_level && root->left == nullptr && root->right == nullptr){
            max_level = level;
            deepest_leaves.clear();
            deepest_leaves.insert(root);
        }else if(level == max_level && root->left == nullptr && root->right == nullptr){
            deepest_leaves.insert(root);
        }
        
        preorder(root->left, level+1);
        preorder(root->right, level+1);
    }
    
    int lca(TreeNode* root, TreeNode*& lca_ans, unordered_set<TreeNode*>& target){
        if(root == nullptr)return 0;
        
        //NOTE: postorder
        int l_target = lca(root->left, lca_ans, target);
        int r_target = lca(root->right, lca_ans, target);
        //NOTE: lca already found in subtree
        if(l_target == target.size() || r_target == target.size()) return target.size();
        
        //NOTE: this node is the first meeting requirements --> it's the lca
        if( (target.find(root) != target.end()) + l_target + r_target == target.size()){
            lca_ans = root;
            return target.size();
        }
        
        return (target.find(root) != target.end()) + l_target + r_target;
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        //get deepest leaves
        preorder(root);
        //lca
        TreeNode* lca_ans;
        lca(root, lca_ans, deepest_leaves);
        return lca_ans;
    }
};
