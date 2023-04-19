//m01
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
enum{
    Left,
    Right,
    No_dir
};
class Solution {
public:
    int max_len = 0;
    void zigzag(TreeNode* root, int len, int last_dir){
        if(!root)return;
        max_len = max(max_len, len);

        zigzag(root->left, (last_dir==Right)? len+1:1, Left);
        zigzag(root->right, (last_dir==Left)? len+1:1, Right);
    }

    int longestZigZag(TreeNode* root) {
        zigzag(root, 0, No_dir);
        return max_len;
    }
};
