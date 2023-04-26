//m1
//bfs with partial sorting. k:=column count, O(k * n/k * log(n/k))
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

bool cmp_fn(const pair<int,int>& a, const pair<int,int>& b){
    if(a.first != b.first) return a.first < b.first;//row
    else return a.second < b.second;//val
}

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        unordered_map<int, vector<pair<int,int>>> col2vec;
        int min_col = INT_MAX, max_col = INT_MIN;

        queue<pair<TreeNode*, int>> q;//(node, col)
        if(!root) return vector<vector<int>>();
        q.push(pair<TreeNode*, int>(root,0));
        
        int level = 0;
        while(q.size() != 0){
            int level_size = q.size();
            for(int l=0;l<level_size;l++){
                auto [node, col] = q.front();
                q.pop();
                col2vec[col].push_back(pair<int,int>(level, node->val));

                min_col = min(min_col, col);
                max_col = max(max_col, col);

                if(node->left) q.push(pair<TreeNode*,int>(node->left, col-1));
                if(node->right) q.push(pair<TreeNode*, int>(node->right, col+1));
            }

            level++;
        }


        vector<vector<int>> ans;
        for(int i=min_col;i<=max_col;i++){
            sort(col2vec[i].begin(), col2vec[i].end(), cmp_fn);

            vector<int> ans1;
            for(const pair<int,int>& p: col2vec[i])
                ans1.push_back(p.second);
            ans.push_back(ans1);
        }
        return ans;
    }
};
