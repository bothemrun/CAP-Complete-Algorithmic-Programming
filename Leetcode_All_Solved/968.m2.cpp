//m2
//greedy: for a node, if both of its children covered, then don't cover it and let its parent cover it.
//and the parent camera may also cover its sibling for addtional benefits.
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
//3 states:
//0: this node has a camera, 1: this node covered, 2: this node not covered
class Solution {
public:
    int cnt = 0;
    int postorder_greedy(TreeNode* root){
        if(!root) return 1;

        int left = postorder_greedy(root->left);
        int right = postorder_greedy(root->right);

        if(left==2 || right==2){
            cnt++;
            return 0;
        }else if(left==0 || right==0) return 1;
        else return 2;
    }
    int minCameraCover(TreeNode* root) {
        //NOTE: edge case
        if(postorder_greedy(root) == 2) cnt++;

        return cnt;
    }
};
