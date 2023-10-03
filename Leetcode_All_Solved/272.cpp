//m0
//O(n) by inorder traversal then binary search

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
#include<assert.h>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> sorted;
    void inorder(TreeNode* root){
        if(!root) return;

        inorder(root->left);
        sorted.push_back(root->val);
        inorder(root->right);
    }

    vector<int> closestKValues(TreeNode* root, double target, int k) {
        inorder(root);

        int n = sorted.size();
        int j = upper_bound(sorted.begin(), sorted.end(), (int)target) - sorted.begin();
        int i = j-1;


        vector<int> ans(k);
        for(int h=0;h<k;h++){
            assert(0<=i || j<n);

            if(!(j<n)){
                ans[h] = sorted[i--];
            }else if(!(0<=i)){
                ans[h] = sorted[j++];
            }else{
                //NOTE: ok for i==j
                if( target - (double)sorted[i] < (double)sorted[j] - target ){
                    ans[h] = sorted[i--];
                }else{
                    ans[h] = sorted[j++];
                }
            }
        }

        return ans;
    }
};
