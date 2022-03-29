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
public:
    int maxLevelSum(TreeNode* root) {
        //NOTE: variant level order traversal, with current level info
        queue<TreeNode*> q;
        q.push(root);
        
        int max_sum = INT_MIN;
        int max_sum_level = 1;
        int cur_level = 1;
        while(q.size()){
            int level_size = q.size();
            int level_sum = 0;
            for(int i=0;i<level_size;i++){
                TreeNode* n = q.front();
                q.pop();
                level_sum += n->val;
                
                if(n->left != nullptr)q.push(n->left);
                if(n->right != nullptr)q.push(n->right);
            }
            
            if(level_sum > max_sum){//return smallest level
                max_sum = level_sum;
                max_sum_level = cur_level;
            }
            cur_level++;
        }
        return max_sum_level;
    }
};
