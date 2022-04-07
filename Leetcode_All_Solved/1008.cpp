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
class Solution {
private:
    TreeNode* divide_conquer(const vector<int>& preorder, int low, int high){
        if(low > high)return nullptr;
        TreeNode* root = new TreeNode(preorder.at(low));
        if(low == high)return root;
        
        int right_low = high+1;
        for(int i=low;i<=high;i++){
            if(preorder.at(i) > preorder.at(low)){
                right_low = i;
                break;
            }
        }
        
        root->left = divide_conquer(preorder, low + 1, right_low - 1);
        root->right = divide_conquer(preorder, right_low, high);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return divide_conquer(preorder, 0, preorder.size()-1);
    }
};
