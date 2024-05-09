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

//level order traversal / bfs + min swap to sort array

#define tii tuple<int,int>
#include<tuple>
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
    int dfs(int node, vector<bool>& visited, const vector<vector<int>>& al){
        if(visited[node]) return 0;
        visited[node] = true;

        int cnt = 1;
        for(const int& child: al[node])
            cnt += dfs(child, visited, al);
        return cnt;
    }

    inline int min_swap_sort(const vector<int>& arr){
        int n = arr.size();
        vector<tii> v2i(n);
        for(int i=0;i<n;i++)
            v2i[i] = tii(arr[i], i);
        
        sort(v2i.begin(), v2i.end());


        vector<vector<int>> al(n);
        for(int i=0;i<n;i++)
            al[i].push_back( get<1>( v2i[i] ) );
        
        int swap = 0;
        vector<bool> visited(n, false);
        for(int i=0;i<n;i++)if(visited[i] == false){
            swap += dfs(i, visited, al) - 1;
        }
        return swap;
    }

    int minimumOperations(TreeNode* root) {
        int ans = 0;

        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            vector<int> level;

            int lsize = q.size();
            for(int l=0;l<lsize;l++){
                TreeNode* node = q.front();
                q.pop();

                level.push_back(node->val);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            ans += min_swap_sort(level);
        }

        return ans;
    }
};
