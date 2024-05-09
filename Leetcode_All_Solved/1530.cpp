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

//m0
//O(n^2), instead of O(n * d^2) = O(n^3)
#include<unordered_map>

class Solution {
public:
    unordered_map<TreeNode*, vector<TreeNode*> > al;
    unordered_set<TreeNode*> leaf;
    int ans = 0;

    void dfs_al(TreeNode* node){
        if(!node) return;

        if(node->left){
            al[node].push_back(node->left);
            al[node->left].push_back(node);
        }

        if(node->right){
            al[node].push_back(node->right);
            al[node->right].push_back(node);
        }

        dfs_al(node->left);
        dfs_al(node->right);

        if(!node->left && !node->right){
            leaf.insert(node);
        }
    }

    void dfs(TreeNode* node, int d, TreeNode* par=nullptr){
        if(d<0) return;
        if(par != nullptr && d>=0 && leaf.count(node) != 0){
            ans++;
        }

        for(TreeNode* child: al[node])if(child != par){
            dfs(child, d-1, node);
        }
    }

    int countPairs(TreeNode* root, int distance) {
        dfs_al(root);

        for(TreeNode* lea: leaf){
            dfs(lea, distance);
        }

        return ans/2;
    }
};
