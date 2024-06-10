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
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int minimumLevel(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        long long min_sum = LLONG_MAX;
        int min_l = 1;

        int level = 1;
        while(q.size()){
            long long sum = 0;

            int lsize = q.size();
            for(int l=0;l<lsize;l++){
                TreeNode* node = q.front();
                q.pop();

                sum += node->val;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            if(sum < min_sum){
                min_sum = sum;
                min_l = level;
            }

            level++;
        }

        return min_l;
    }
};
