//m1
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
#include<limits.h>
class Solution {
private:
    inline bool check(TreeNode* n, int cur_level, int level_prev_val){
        if(cur_level % 2 == 0){
            if(!(n->val % 2 == 1))return false;
            if(!(level_prev_val < n->val))return false;
        }else{
            if(!(n->val %2 == 0))return false;
            if(!(level_prev_val > n->val))return false;
        }
        return true;
    }
public:
    bool isEvenOddTree(TreeNode* root) {
        //NOTE: level order traversal, but queue only stores 1 levle, and size := current level size
        queue<TreeNode*> q;
        if(root == nullptr)return true;
        q.push(root);
        int level_prev_val = INT_MIN;
        int cur_level = 0;
        while(q.size() != 0){
            int level_size = q.size();
            for(int i=0;i<level_size;i++){
                TreeNode* n = q.front();
                q.pop();
                
                if(check(n, cur_level, level_prev_val) == false)return false;
                
                level_prev_val = n->val;
                
                if(n->left != nullptr)q.push(n->left);
                if(n->right != nullptr)q.push(n->right);
            }//NOTE: end of 1 level
            
            cur_level++;//NOTE: get levels on the run
            if(cur_level %2 == 0)level_prev_val = INT_MIN;
            else level_prev_val = INT_MAX;
        }
        return true;
    }
};
