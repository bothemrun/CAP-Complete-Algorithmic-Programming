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
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        //NOTE: level order traversal, and check #children = (2,...,2,) (1)(must be left child), 0,...,0
        queue<TreeNode*> q;
        q.push(root);
        vector<int> prev_n_children {0,1,2};
        while(q.size() != 0){
            TreeNode* n = q.front();
            q.pop();
            
            //check completeness
            int n_children = (int)(n->left != nullptr) + (int)(n->right != nullptr);
            if(n_children == 1 && n->left == nullptr)return false;//NOTE: 1 child node must be of left child
            if(prev_n_children.back() == 2){
                //if(n_children == 2) do nothing. good
                if(n_children == 1) prev_n_children.pop_back();
                else if(n_children == 0){
                    prev_n_children.pop_back();
                    prev_n_children.pop_back();
                }//no other possibility of n_children
            }else if(prev_n_children.back() == 1){
                if(n_children == 0) prev_n_children.pop_back();
                else return false;//for 1, 2
            }else if(prev_n_children.back() == 0){
                if(n_children != 0)return false;
            }
            
            if(n->left != nullptr)q.push(n->left);
            if(n->right != nullptr)q.push(n->right);
        }
        return true;
    }
};
