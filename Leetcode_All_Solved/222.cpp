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
#include<queue>
class Solution {
public:
    int countNodes(TreeNode* root) {
        //NOTE: just level order traversal ?
        queue<TreeNode*> q;
        if(root == nullptr)return 0;
        q.push(root);
        int ans = 0;
        while(q.size() != 0){
            TreeNode* n = q.front();
            q.pop();
            ans++;
            if(n->left != nullptr)q.push(n->left);
            if(n->right != nullptr)q.push(n->right);
        }
        return ans;
    }
};
