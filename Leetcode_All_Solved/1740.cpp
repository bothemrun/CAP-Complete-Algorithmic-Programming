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
public:
    int lca_dist(TreeNode* root, const int& p, const int& q, int& dist){
        if(root == nullptr)return 0;

        int l = lca_dist(root->left, p, q, dist);
        int r = lca_dist(root->right, p, q, dist);

        //NOTE: includes:
        //1. p == q == root->val
        //2. p != q, but p == root->val
        int cnt = (l != 0) + (r != 0) + (root->val == p) + (root->val == q);
        if(cnt == 2) dist = l + r;

        //NOTE: if got lca, then don't care about return values.
        if(root->val == p || root->val == q)return 1;
        else if(l != 0)return l + 1;
        else if(r != 0)return r + 1;
        else return 0;
    }
    int findDistance(TreeNode* root, int p, int q) {
        int dist;
        lca_dist(root, p, q, dist);
        return dist;
    }
};
