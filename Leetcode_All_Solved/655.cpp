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
#include<algorithm>
#include<utility>
class Solution {
private:
    void get_height(TreeNode* root, int& max_height, int cur_height=(-1)){
        if(root == nullptr){
            max_height = max(max_height, cur_height);
            return;
        }
        get_height(root->left, max_height, cur_height+1);
        get_height(root->right, max_height, cur_height+1);
    }
public:
    vector<vector<string>> printTree(TreeNode* root) {
        int max_height = 0;
        get_height(root, max_height);
        
        int m = max_height + 1;
        int n = (1 << (max_height+1)) - 1;
        vector<vector<string>> res(m, vector<string>(n, ""));
        
        int cur_height = 0;
        queue< pair<TreeNode*,int> > q2c;
        q2c.push( {root, (n-1)/2} );
        while(q2c.size() != 0){
            int level_size = q2c.size();
            for(int i=0;i<level_size;i++){
                pair<TreeNode*, int> n2c = q2c.front();
                q2c.pop();
                int col = n2c.second;
                TreeNode* node = n2c.first;
                res[cur_height][col] = to_string(node->val);
                
                if(node->left) q2c.push( {node->left, col - (1 << (max_height-cur_height-1)) } );
                if(node->right) q2c.push( {node->right, col + (1 << (max_height-cur_height-1)) } );
            }
            cur_height++;
        }
        return res;
    }
};
