//m3
//greedy: for a node, if both of its children covered, then don't cover it and let its parent cover it.
//and the parent camera may also cover its sibling for addtional benefits.

//use enum.

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
enum{
    has_camera,
    covered,
    not_covered
};
class Solution {
public:
    int cnt = 0;
    int postorder_greedy(TreeNode* root){
        if(!root) return covered;

        int left = postorder_greedy(root->left);
        int right = postorder_greedy(root->right);

        if(left==not_covered || right==not_covered){
            cnt++;
            return has_camera;
        }else if(left==has_camera || right==has_camera) return covered;
        else return not_covered;
    }
    int minCameraCover(TreeNode* root) {
        //NOTE: edge case
        if(postorder_greedy(root) == not_covered) cnt++;

        return cnt;
    }
};
