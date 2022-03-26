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
#include<utility>
#include<queue>
class Solution {
private:
    void preorder_level(TreeNode* root, unordered_map<TreeNode*,int>& level_m, int level=0){
        if(root == nullptr)return;
        
        pair<TreeNode*,int> p (root, level);
        level_m.insert(p);
        
        preorder_level(root->left, level_m, level+1);
        preorder_level(root->right, level_m, level+1);
    }
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        //get levels
        unordered_map<TreeNode*,int> level_m;
        preorder_level(root,level_m);
        
        //level order traversal
        vector<vector<int>> ans_rev;
        vector<int> ans1level;
        queue<TreeNode*> q;
        if(root == nullptr)return ans_rev;
        q.push(root);
        
        int cur_level = 0;
        while(q.size() != 0){
            TreeNode* n = q.front();
            q.pop();
            
            if(level_m.find(n)->second == cur_level+1){
                ans_rev.push_back(ans1level);
                ans1level.clear();
                cur_level++;
            }
            
            ans1level.push_back(n->val);
            if(n->left != nullptr)q.push(n->left);
            if(n->right != nullptr)q.push(n->right);
        }
        ans_rev.push_back(ans1level);
        
        //bottom level order
        vector<vector<int>> ans;
        for(int i=ans_rev.size()-1;i>=0;i--) ans.push_back(ans_rev[i]);
        
        return ans;
    }
};
