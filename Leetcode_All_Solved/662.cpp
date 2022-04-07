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
#include<algorithm>
class Solution {
private:
    vector<vector<unsigned long long>> cbt_idx;
    void dfs(TreeNode* root, int level=0, unsigned long long cbt=1){
        if(root == nullptr)return;
        if(cbt_idx.size() == level){
            cbt_idx.push_back( vector<unsigned long long>({cbt}) );
        }else cbt_idx.at(level).push_back(cbt);
        
        //NOTE: complete binary tree index representation
        dfs(root->left, level+1, cbt*2);
        dfs(root->right, level+1, cbt*2+1);
    }
public:
    int widthOfBinaryTree(TreeNode* root) {
        dfs(root);
        
        unsigned long long max_width = 0;
        for(vector<unsigned long long>& cbt_level:cbt_idx){
            sort(cbt_level.begin(), cbt_level.end());
            max_width = max(max_width, cbt_level.back() - cbt_level.front() + 1);
        }
        return max_width;
    }
};
