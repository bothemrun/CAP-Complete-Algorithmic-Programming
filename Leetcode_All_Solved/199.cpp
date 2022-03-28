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
#include<unordered_map>
#include<queue>
class Solution {
private:
    unordered_map<TreeNode*,int> level_m;
    void preorder_level(TreeNode* root, int level=0){
        if(root == nullptr)return;
        
        this->level_m[root] = level;
        preorder_level(root->left, level+1);
        preorder_level(root->right, level+1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        //get level
        preorder_level(root);
        
        //level order traversal
        vector<int> ans;
        queue<TreeNode*> q;
        if(root == nullptr)return ans;
        q.push(root);
        int cur_level = 0;
        TreeNode* pre_node;
        while(q.size() != 0){
            TreeNode* cur_node = q.front();
            q.pop();
            if(this->level_m[cur_node] == cur_level+1){
                cur_level++;
                ans.push_back(pre_node->val);
            }
            
            pre_node = cur_node;
            if(cur_node->left != nullptr)q.push(cur_node->left);
            if(cur_node->right != nullptr)q.push(cur_node->right);
        }
        ans.push_back(pre_node->val);
        
        return ans;
    }
};
