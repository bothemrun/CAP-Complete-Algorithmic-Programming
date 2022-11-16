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
#include<queue>
#include<unordered_set>
#include<unordered_map>
#include<assert.h>
class Solution {
public:
    TreeNode* correctBinaryTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        
        unordered_map<TreeNode*, TreeNode*> child2parent;
        while(q.size() != 0){
            int level_size = q.size();
            
            unordered_set<TreeNode*> level_suffix;
            for(int i=0;i<level_size;i++){
                TreeNode* n = q.front();
                q.pop();
                
                if(level_suffix.count(n->right) > 0){//root won't come here, for 1st level
                    //delete subtree
                    TreeNode* parent = child2parent[n];
                    if(parent->left == n) parent->left = nullptr;
                    else if(parent->right == n) parent->right = nullptr;
                    else assert(false);
                    return root;
                }//else{
                
                //NOTE: level from right to left
                if(n->right != nullptr){
                    q.push(n->right);
                    child2parent[n->right] = n;
                }
                if(n->left != nullptr){
                    q.push(n->left);
                    child2parent[n->left] = n;
                }
                
                level_suffix.insert(n);
            }//for
            
            level_suffix.clear();
        }//while
        
        assert(false);
        return root;
    }
};
