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
#include<algorithm>
#include<assert.h>
#include<utility>
bool cmp_fn(const pair<int,int>& a, const pair<int,int>& b){
    return a.first < b.first;//min, sorted
}

class Solution {
public:
    unordered_map<TreeNode*, int> target_path2d;

    bool get_target_path(TreeNode* root, const int& target, int& d2target_ret){
        if(root == nullptr)return false;
        if(root->val == target){
            target_path2d[root] = 0;

            d2target_ret = 1;
            return true;
        }

        int d2target_ret0, d2target_ret1;
        bool l = get_target_path(root->left, target, d2target_ret0);
        bool r = false;
        if(l == false)
            r = get_target_path(root->right, target, d2target_ret1);
        
        if(l) target_path2d[root] = d2target_ret0;
        else if(r) target_path2d[root] = d2target_ret1;

        if(l || r) d2target_ret = target_path2d[root] + 1;

        return l || r;

    }

    pair<int,int> get_min_leaf(TreeNode* root){
        if(root == nullptr)return pair<int,int>(INT_MAX, (-1));//NOTE

        if(root->left==nullptr && root->right==nullptr){
            return pair<int,int>(0, root->val);
        }

        pair<int,int> min_leaf(INT_MAX, (-1));
        if(target_path2d.count(root->left) == 0 )
            min_leaf = min(min_leaf, get_min_leaf(root->left), cmp_fn );
        
        if(target_path2d.count(root->right) == 0 )
            min_leaf = min(min_leaf, get_min_leaf(root->right), cmp_fn );
        
        
        //NOTE: on target path, and only 1 child
        if(min_leaf.first == INT_MAX)
            return pair<int,int>(INT_MAX, (-1));

        return pair<int,int>(min_leaf.first + 1, min_leaf.second);
    }

    int findClosestLeaf(TreeNode* root, int k) {
        int d2target_ret;
        get_target_path(root, k, d2target_ret);

        pair<int,int> min_leaf(INT_MAX, (-1));
        for(unordered_map<TreeNode*, int>::iterator it = target_path2d.begin();it != target_path2d.end();it++){
            pair<int,int> d_val = get_min_leaf(it->first);

            //NOTE: on target path, and only 1 child
            if(d_val.first == INT_MAX)continue;

            d_val.first += it->second;

            min_leaf = min(min_leaf, d_val, cmp_fn);
        }

        return min_leaf.second;
    }
};



