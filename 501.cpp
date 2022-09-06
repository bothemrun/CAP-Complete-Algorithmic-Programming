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
#include<unordered_set>
#include<limits.h>
class Solution {
public:
    unordered_set<int> modes;
    int max_modes_cnt = 0;
    int same_streak_cnt = 0;
    void sorted_inorder(TreeNode *root, int& inorder_last_val){
        if(root == nullptr)return;
        
        sorted_inorder(root->left, inorder_last_val);
        
        if(inorder_last_val == INT_MIN){
            //cornder case: first element
            max_modes_cnt = 1;
            same_streak_cnt = 1;
            modes.insert(root->val);
        }else if(inorder_last_val == root->val){
            same_streak_cnt++;
            if(same_streak_cnt > max_modes_cnt){
                modes.clear();
                modes.insert(root->val);
                max_modes_cnt = same_streak_cnt;
            }else if(same_streak_cnt == max_modes_cnt){
                modes.insert(root->val);
            }
        }else{
            //NOTE:
            same_streak_cnt = 1;
            if(same_streak_cnt == max_modes_cnt) modes.insert(root->val);
            //no >, due to root
        }
        inorder_last_val = root->val;
        
        sorted_inorder(root->right, inorder_last_val);
    }
    vector<int> findMode(TreeNode* root) {
        //NOTE: inorder is sorted
        int inorder_last_val = INT_MIN;//NOTE: corner case
        sorted_inorder(root, inorder_last_val);
        
        vector<int> modes_vec;
        for(int val:modes) modes_vec.push_back(val);
        return modes_vec;
    }
};
