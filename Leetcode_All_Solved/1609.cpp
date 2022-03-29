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
#include<unordered_map>
#include<limits.h>
class Solution {
private:
    unordered_map<TreeNode*,int> level_m;
    void preorder_level(TreeNode* root, int level=0){
        if(root==nullptr)return;
        level_m[root] = level;
        preorder_level(root->left,level+1);
        preorder_level(root->right,level+1);
    }
public:
    bool isEvenOddTree(TreeNode* root) {
        //get levels
        preorder_level(root);
        
        //just yet another level order traversal
        queue<TreeNode*> q;
        if(root == nullptr)return root->val % 2 == 1;
        q.push(root);
        int cur_level = 0;
        int level_prev_val = INT_MIN;
        while(q.size() != 0){
            TreeNode* n = q.front();
            q.pop();
            
            if(level_m[n] == cur_level+1){
                cur_level++;
                if(cur_level %2 == 0) level_prev_val = INT_MIN;
                else level_prev_val = INT_MAX;
            }
            if(cur_level %2 == 0 && !(level_prev_val < n->val) )return false;
            if(cur_level %2 == 1 && !(level_prev_val > n->val) )return false;
            if(cur_level % 2 == 0 && !(n->val %2 == 1))return false;
            if(cur_level %2 == 1 &&!(n->val %2 == 0))return false;
            
            if(n->left != nullptr)q.push(n->left);
            if(n->right != nullptr)q.push(n->right);
            
            level_prev_val = n->val;
        }
        return true;
    }
};
