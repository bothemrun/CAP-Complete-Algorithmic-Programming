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
#include<stack>
class BSTIterator {
    //NOTE: just simulate inorder traversal
    stack<TreeNode*> s;
    void inorder_step1(TreeNode* root){
        while(root != nullptr){
            s.push(root);
            root = root->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        inorder_step1(root);
    }
    
    int next() {
        TreeNode* n = s.top();
        s.pop();
        inorder_step1(n->right);
        
        return n->val;
    }
    
    bool hasNext() {
        return s.size() != 0;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
