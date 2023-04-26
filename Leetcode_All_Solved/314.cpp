//m0
//dfs with partial stable_sort(). k:=column count, O(k * n/k * log(n/k))
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
#include<unordered_map>
#include<utility>

bool cmp_fn(const pair<int,int>& a, const pair<int,int>& b){
    return a.first < b.first;//row
}

class Solution {
public:
    unordered_map<int, vector<pair<int,int>>> col2vec;
    int min_col = INT_MAX, max_col = INT_MIN;
    void dfs_left_1st(TreeNode* root, const int& col=0, const int& row=0){
        if(!root)return;

        min_col = min(min_col, col);
        max_col = max(max_col, col);
        col2vec[col].push_back(pair<int,int>(row, root->val));

        dfs_left_1st(root->left, col-1, row+1);
        dfs_left_1st(root->right, col+1, row+1);
    }

    vector<vector<int>> verticalOrder(TreeNode* root) {
        dfs_left_1st(root);

        vector<vector<int>> ans;
        //edge case: node count == 0
        for(int i=min_col;i<=max_col;i++){
            stable_sort(col2vec[i].begin(), col2vec[i].end(), cmp_fn);

            vector<int> ans1;
            for(const pair<int,int>& p: col2vec[i])
                ans1.push_back(p.second);
            ans.push_back(ans1);
        }

        return ans;
    }
};
