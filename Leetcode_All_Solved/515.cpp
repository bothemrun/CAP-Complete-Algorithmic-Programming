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
#include<algorithm>
class Solution {
    unordered_map<int,int> row_max;
    vector<int> map2vec(){
        vector<int> ans(row_max.size(), 0);
        for(unordered_map<int,int>::iterator it = this->row_max.begin();it != this->row_max.end();it++)
            ans[it->first] = it->second;
        return ans;
    }
    void preorder_level(TreeNode* root, int level=0){
        if(root == nullptr)return;
        
        if(this->row_max.find(level) == this->row_max.end())this->row_max[level] = root->val;
        else this->row_max[level] = max(this->row_max[level], root->val);
        
        preorder_level(root->left, level+1);
        preorder_level(root->right, level+1);
    }
public:
    vector<int> largestValues(TreeNode* root) {
        preorder_level(root);
        return map2vec();
    }
};
