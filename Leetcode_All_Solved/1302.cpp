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
    int max_level = 0;
    int sum = 0;
    void preorder(TreeNode* root, int level=0){
        if(root==nullptr)return;
        if(level > max_level){
            max_level = level;
            sum = root->val;
        }else if(level == max_level){
            sum += root->val;
        }
        
        preorder(root->left, level+1);
        preorder(root->right, level+1);
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        //NOTE: don't get levels first alone. get levels on the run
        preorder(root);
        return this->sum;
    }
};
