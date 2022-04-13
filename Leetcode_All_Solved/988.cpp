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
    string lexi_min = "";
    void preorder(TreeNode* root, string path=""){
        if(root==nullptr)return;//not leaf
        
        path = (char)(root->val + 'a') + path;//NOTE: (int+char)+string
        if(root->left == nullptr && root->right == nullptr){
            if(lexi_min == "" || lexi_min.compare(path) > 0)
                lexi_min = path;
            return;
        }
        
        preorder(root->left, path);
        preorder(root->right, path);
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        preorder(root);
        return lexi_min;
    }
};
