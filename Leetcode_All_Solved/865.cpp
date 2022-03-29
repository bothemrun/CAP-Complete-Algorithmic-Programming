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
    unordered_set<TreeNode*> deepest_set;
    int max_level = 0;
    void preorder_deepest_leaf(TreeNode* root, int level=0){
        if(root == nullptr)return;
        if(level > max_level && root->left == nullptr && root->right == nullptr){
            max_level = level;
            deepest_set.clear();
            deepest_set.insert(root);
        }else if(level == max_level && root->left == nullptr && root->right == nullptr)deepest_set.insert(root);
        
        preorder_deepest_leaf(root->left, level+1);
        preorder_deepest_leaf(root->right, level+1);
    }
    
    int get_lca(TreeNode* root, const unordered_set<TreeNode*>& target, TreeNode*& lca){
        if(root==nullptr)return 0;
        int l_lca = get_lca(root->left, target, lca);
        int r_lca = get_lca(root->right, target, lca);
        
        if(l_lca == target.size() || r_lca == target.size())
            return target.size();//descendants already found target.
        
        int root_lca = (target.find(root) != target.end()) + l_lca + r_lca;
        if(root_lca == target.size()){
            lca = root;
            return target.size();
        }
        return root_lca;
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        //get deepest nodes
        preorder_deepest_leaf(root);
        //get lca of deepest nodes
        TreeNode* lca;
        get_lca(root, this->deepest_set, lca);
        return lca;
    }
};
