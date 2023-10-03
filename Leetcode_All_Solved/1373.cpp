//O(n)

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
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Sub{
public:
    bool bst;
    int sum; //no overflow
    int min;
    int max;
    Sub(const bool bst_, const int& sum_, const int& min_, const int& max_){
        bst = bst_;
        sum = sum_;
        min = min_;
        max = max_;
    }
    Sub(const bool bst_){
        bst = bst_;
        sum = 0;
        min = INT_MAX;
        max = INT_MIN;
    }
};

class Solution {
public:
    //NOTE: not INT_MIN, for the empty sbutree.
    int max_sum = 0;

    class Sub* postorder(TreeNode* root){
        if(!root)
            return new Sub(true);
        
        class Sub* left = postorder(root->left);
        class Sub* right = postorder(root->right);

        if(!(left->bst && right->bst))
            return new Sub(false);
        
        if(!( left->max < root->val && root->val < right->min ))
            return new Sub(false);
        
        int sum = left->sum + root->val + right->sum;

        //NOTE: now this node and its subtrees are bst.
        max_sum = max(max_sum, sum);
        
        return new Sub(true, sum, 
            min(left->min, root->val),
            max(right->max, root->val)
        );
    }

    int maxSumBST(TreeNode* root) {
        postorder(root);
        return max_sum;
    }
};
