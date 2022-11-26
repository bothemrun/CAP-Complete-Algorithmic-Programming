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
public:
    int count_postorder(TreeNode* root, unordered_set<TreeNode*>& nodes_set, TreeNode*& lca){
        if(root == nullptr)return 0;
        
        int l_count = count_postorder(root->left, nodes_set, lca);
        int r_count = count_postorder(root->right, nodes_set, lca);
        if(l_count == nodes_set.size() || r_count == nodes_set.size())
            return nodes_set.size();
        
        int count = l_count + r_count + (nodes_set.count(root) != 0);
        if(count == nodes_set.size())
            lca = root;
        return count;
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        TreeNode* lca;
        unordered_set<TreeNode*> nodes_set;
        for(TreeNode* node: nodes) nodes_set.insert(node);
        count_postorder(root, nodes_set, lca);
        return lca;
    }
};
