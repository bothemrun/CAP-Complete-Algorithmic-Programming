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
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> sum;

        queue<TreeNode*> q;
        q.push(root);

        while(q.size()){
            int lsize = q.size();
            long long level_sum = 0;

            for(int l=0;l<lsize;l++){
                TreeNode* node = q.front();
                q.pop();

                level_sum += node->val;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            sum.push_back(level_sum);
        }

        if(sum.size() < k) return (-1);
        auto cmp = [](const long long& a, const long long& b){
            return a>b;
        };
        nth_element(sum.begin(), sum.begin() + (k-1), sum.end(), cmp);

        return sum.at(k-1);
    }
};
