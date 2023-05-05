//m4
//still dp, but dynamic allocating vectors for return

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
//NOTE: min cameras for 3 states: 
//0: this node has a camera
//1: this node covered
//2: this node not covered
#define state_inf 1002
#include<algorithm>
enum{
    has_camera,
    covered,
    not_covered
};
class Solution {
public:
    vector<int>* postorder3(TreeNode* root){
        //NOTE: not (0, 0, 0)
        if(!root) return new vector<int>({state_inf, 0, 0});

        vector<int>* left = postorder3(root->left);
        vector<int>* right = postorder3(root->right);

        return new vector<int>({
            1 + 
            *min_element(left->begin(), left->end()) +
            *min_element(right->begin(), right->end()),

            min({
                left->at(has_camera) + right->at(has_camera),
                left->at(covered) + right->at(has_camera),
                left->at(has_camera) + right->at(covered)
            }),

            left->at(covered) + right->at(covered)
        });
    }
    int minCameraCover(TreeNode* root) {
        vector<int>* state = postorder3(root);
        return min(state->at(has_camera), state->at(covered));
    }
};
