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
    bool check_preorder(TreeNode* root, TreeNode* subRoot){
        if(root == nullptr && subRoot == nullptr)return true;
        if( root==nullptr ^ subRoot==nullptr )return false;
        if(root->val != subRoot->val)return false;
        
        return check_preorder(root->left, subRoot->left) && check_preorder(root->right, subRoot->right);
    }
    bool find_preorder(TreeNode* root, TreeNode* subRoot){
        if(root==nullptr)return false;
        if(root->val == subRoot->val)
            if(check_preorder(root, subRoot) == true)
                return true;
        return find_preorder(root->left, subRoot) || find_preorder(root->right, subRoot);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return find_preorder(root, subRoot);
    }
};
