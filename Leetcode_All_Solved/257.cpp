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
#include<string>
class Solution {
private:
    string make_ans(const vector<int> &cur_ans){
        string ans1 = "";
        for(int i=0;i<cur_ans.size();i++){
            if(i != 0) ans1 += "->";
            ans1 += to_string(cur_ans.at(i));
        }
        return ans1;
    }
    void backtrack(TreeNode *root, vector<string>& ans, vector<int>& cur_ans){
        cur_ans.push_back(root->val);
        
        if(root->left == nullptr && root->right == nullptr){
            ans.push_back( make_ans(cur_ans) );
            cur_ans.pop_back();
            return;
        }
        
        if(root->left != nullptr)
            backtrack(root->left, ans, cur_ans);
        if(root->right != nullptr)
            backtrack(root->right, ans, cur_ans);
        
        cur_ans.pop_back();
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        vector<int> cur_ans;
        backtrack(root, ans, cur_ans);
        return ans;
    }
};
