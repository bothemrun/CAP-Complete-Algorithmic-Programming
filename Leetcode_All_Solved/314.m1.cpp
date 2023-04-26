//m1
//bfs in O(n) by utilizaing bfs properties.
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
#include<limits.h>
#include<queue>
#include<utility>
#include<unordered_map>
#include<iostream>

static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        unordered_map<int, vector<int>> col2vec;
        int min_col = INT_MAX, max_col = INT_MIN;

        queue<pair<TreeNode*, int>> q;//(node, col)
        if(!root) return vector<vector<int>>();
        q.push(pair<TreeNode*,int>(root, 0));

        int level = 0;
        while(q.size() != 0){
            int level_size = q.size();
            for(int l=0;l<level_size;l++){
                auto [node, col] = q.front();
                q.pop();

                min_col = min(min_col, col);
                max_col = max(max_col, col);
                col2vec[col].push_back(node->val);

                //NOTE: must go left first, stable_sort()
                if(node->left) q.push(pair<TreeNode*, int>(node->left, col-1));
                if(node->right) q.push(pair<TreeNode*, int>(node->right, col+1));
            }

            level++;
        }


        vector<vector<int>> ans;
        for(int i=min_col;i<=max_col;i++)
            ans.push_back(col2vec[i]);//NOTE: bfs already sorted in rows & left to right
        return ans;
    }
};
