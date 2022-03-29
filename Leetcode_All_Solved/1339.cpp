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
#include<unordered_map>
#include<limits.h>
#define MODULO (1000000000+7)
class Solution {
private:
    long long max_product = 0;
    
    unordered_map<TreeNode*,long long> subtree_sum;
    long long get_subtree_sum(TreeNode* root){
        if(root == nullptr)return 0;
        long long l_sum = get_subtree_sum(root->left);
        long long r_sum = get_subtree_sum(root->right);
        long long sum = root->val + l_sum + r_sum;
        subtree_sum[root] = sum;
        return sum;
    }
    
    void get_max_product(TreeNode* root, TreeNode* top_root){
        if(root == nullptr)return;
        long long product = 1;
        long long cut_left_product = LLONG_MIN, cut_right_product = LLONG_MIN;
        if(root->left != nullptr)cut_left_product = subtree_sum[root->left] * (subtree_sum[top_root] - subtree_sum[root->left]);
        if(root->right != nullptr)cut_right_product = subtree_sum[root->right] * (subtree_sum[top_root] - subtree_sum[root->right]);
        max_product = max(max_product, cut_left_product);
        max_product = max(max_product, cut_right_product);
        
        get_max_product(root->left, top_root);
        get_max_product(root->right, top_root);
    }
public:
    int maxProduct(TreeNode* root) {
        //get subtree sums
        get_subtree_sum(root);
        
        //traverse, get max product
        get_max_product(root, root);
        return max_product % MODULO;
    }
};
