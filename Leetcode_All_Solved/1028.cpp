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
#define PII pair<int, int>
#include<utility>
#include<assert.h>

class Solution {
public:
    vector<PII> depth2val;

    TreeNode* preorder(int& idx, const int& depth=0){
        if(!(idx < depth2val.size())){
            return nullptr;
        }

        if(depth != depth2val[idx].first){
            return nullptr;
        }

        TreeNode* node = new TreeNode(depth2val[idx].second);
        idx++;

        //may be nullptr
        node->left = preorder(idx, depth+1);
        node->right = preorder(idx, depth+1);

        return node;
    }

    TreeNode* recoverFromPreorder(string traversal) {
        int tn = traversal.size();
        int i=0;
        while(i<tn){
            //NOTE: start of dashes
            //NOTE: ok for the root.
            int j = i-1;
            while(j+1<tn && traversal[j+1] == '-'){
                j++;
            }
            int depth = j - (i-1);

            //start of digits
            int digit_start = j+1;
            int k = digit_start;
            assert(k<tn);
            assert(traversal[k] != '-');

            while(k+1<tn && traversal[k+1] != '-'){
                k++;
            }


            depth2val.push_back( PII(
                depth,
                stoi( traversal.substr(digit_start, k - (digit_start-1) ) )
            ) );


            //update
            i = k+1;
        }

        
        int idx = 0;
        TreeNode* root = preorder(idx);
        assert(idx == depth2val.size());
        return root;
    }
};
