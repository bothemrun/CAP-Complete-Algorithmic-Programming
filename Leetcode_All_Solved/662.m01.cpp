//m01
//only unsigned long long works for cbt indexing.

//NOTE: complete binary tree indexing (used in binary heap):
//NOTE: root:1, left: parent*2, right: parent*2+1
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
#include<algorithm>
class Solution {
public:
    unsigned long long max_width = 0;
    unordered_map<int, unsigned long long> level_front;
    void cbt_indexing(TreeNode* root, const int& level, const unsigned long long& cbt_idx){
        if(!root)return;
        
        if(level_front.count(level) == 0) level_front[level] = cbt_idx;

        //NOTE: edge case: the level has only 1 node
        max_width = max(max_width, cbt_idx - level_front[level] + 1);

        cbt_indexing(root->left, level+1, cbt_idx*2);
        cbt_indexing(root->right, level+1, cbt_idx*2 + 1);
    }

    int widthOfBinaryTree(TreeNode* root) {
        cbt_indexing(root, 0, 1);
        return (int)max_width;
    }
};
