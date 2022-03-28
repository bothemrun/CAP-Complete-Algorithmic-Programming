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
#include<limits.h>
class Solution {
private:
    int max_path_with_root(TreeNode* root, int& max_path){
        //maintain global max_path, where it can sum up 2 subtrees
        //return path sum, where upper nodes can connect with this root, so only sum up at most 1 subtree
        if(root == nullptr)return INT_MIN;
        
        int l_connect_sum = max(0, max_path_with_root(root->left, max_path) );//can choose or not choose
        int r_connect_sum = max(0, max_path_with_root(root->right, max_path) );
        
        max_path = max(max_path, root->val + l_connect_sum + r_connect_sum);//update global, connected to this root
        
        return root->val + max(l_connect_sum, r_connect_sum);//upper nodes can connect with this root
    }
public:
    int maxPathSum(TreeNode* root) {
        int max_path = INT_MIN;
        max_path_with_root(root, max_path);
        return max_path;
    }
};
