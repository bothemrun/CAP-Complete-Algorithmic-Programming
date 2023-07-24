//m1
//actually clone results from memo.

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

class Solution {
public:
    unordered_map<int, vector<TreeNode*>> memo;
    vector<bool> memo_done;

    TreeNode* clone(TreeNode* root){
        if(root==nullptr) return nullptr;

        TreeNode* root_clone = new TreeNode(0);
        root_clone->left = clone(root->left);
        root_clone->right = clone(root->right);
        return root_clone;
    }

    bool enum_left_right_clone(const int& n){
        if(memo_done[n] == true) return true;
        if(n==0){
            memo[0] = {nullptr};
            return memo_done[0] = true;
        }
        if(n==1){
            memo[1] = {new TreeNode(0)};
            return memo_done[1] = true;
        }

        //n==1 (no children) ruled out
        for(int left_n=1;left_n <= n-2;left_n++){
            int right_n = n-1 - left_n;
            enum_left_right_clone(left_n);
            enum_left_right_clone(right_n);

            for(const auto& l: memo[left_n])
                for(const auto& r: memo[right_n]){
                    TreeNode* root1 = new TreeNode(0);
                    //NOTE: actually cloned
                    root1->left = clone(l);
                    root1->right = clone(r);

                    memo[n].push_back(root1);
                }
        }

        return memo_done[n] = true;
    }
    
    vector<TreeNode*> allPossibleFBT(int n) {
        memo_done.resize(n + 1, false);
        enum_left_right_clone(n);
        return memo[n];
    }
};
