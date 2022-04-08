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
class Solution {
private:
    vector<int> digit = vector<int>(10, 0);
    int ans = 0;
    void pseudo_palindromic(){
        int n_odd = 0;
        for(int i=1;i<=9;i++)
            if(digit.at(i) %2 == 1)
                if(++n_odd > 1)return;
        ans++;
    }
    void backtrack(TreeNode* root){
        if(root==nullptr)return;
        
        digit.at(root->val)++;
        if(root->left==nullptr && root->right==nullptr){
            pseudo_palindromic();
            digit.at(root->val)--;//NOTE: backtrack
            return;
        }
        backtrack(root->left);
        backtrack(root->right);
        digit.at(root->val)--;//NOTE: backtrack
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        backtrack(root);
        return ans;
    }
};
