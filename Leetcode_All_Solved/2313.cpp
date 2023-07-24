//NOTE: for any tree, the evaluation of true or false can certainly be achieved.
//proof: by De Morgan's Law.


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
#define notyet (-1)
#include<unordered_map>
#include<assert.h>
#include<algorithm>
#include<limits.h>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    unordered_map<TreeNode*, vector<int>> memo;
    inline bool has(TreeNode* node, bool target){
        if(memo.count(node) == 0) return false;
        assert(memo[node].size() == 2);
        return memo[node].at(target) != notyet;
    }
    inline void insert(TreeNode* node, bool target, const int& val){
        if(memo.count(node) == 0){
            memo[node] = vector<int>(2, notyet);
        }
        
        memo[node].at(target) = val;
    }

    int enum_bool(TreeNode* root, bool target){
        assert(root);
        if(!root->left && !root->right) return (target == root->val)? 0:1;
        assert(root->val >= 2);

        if(has(root, target) == true) return memo[root].at(target);


        int val = root->val;
        if(val != 5) assert(root->left && root->right);

        int min_op = INT_MAX;

        if(val == 2){//OR
            if(target == true){
                min_op = min({
                    enum_bool(root->left, true) + enum_bool(root->right, true),
                    enum_bool(root->left, true) + enum_bool(root->right, false),
                    enum_bool(root->left, false) + enum_bool(root->right, true)
                });
            }else{
                min_op = enum_bool(root->left, false) + enum_bool(root->right, false);
            }

        }else if(val == 3){//AND
            if(target == false){
                min_op = min({
                    enum_bool(root->left, false) + enum_bool(root->right, false),
                    enum_bool(root->left, false) + enum_bool(root->right, true),
                    enum_bool(root->left, true) + enum_bool(root->right, false)
                });
            }else{
                min_op = enum_bool(root->left, true) + enum_bool(root->right, true);
            }

        }else if(val == 4){//XOR
            if(target == true){
                min_op = min(
                    enum_bool(root->left, false) + enum_bool(root->right, true),
                    enum_bool(root->left, true) + enum_bool(root->right, false)
                );
            }else{
                min_op = min(
                    enum_bool(root->left, false) + enum_bool(root->right, false),
                    enum_bool(root->left, true) + enum_bool(root->right, true)
                );
            }

        }else if(val == 5){//NOT
            bool l = root->left, r = root->right;
            if(l && !r){
                min_op = enum_bool(root->left, !target );
            }else if(!l && r){
                min_op = enum_bool(root->right, !target );
            }else{
                assert(false);
            }

        }else{
            assert(false);
        }

        
        insert(root, target, min_op);
        return min_op;
    }

    int minimumFlips(TreeNode* root, bool result) {
        return enum_bool(root, result);
    }
};
