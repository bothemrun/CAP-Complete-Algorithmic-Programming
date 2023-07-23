//m0
//recursion with memo
//not cloning nodes

//the trees are actually a DAG, 
//'cuz with memo, we are using the same node addressses.
//so two different trees may have the same tree as the subtree

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
class Solution {
public:
    unordered_map<int, vector<TreeNode*>> memo;

    vector<TreeNode*> enum_left_right(const int& n){
        if(n==0) return {};
        if(n==1) return {new TreeNode(0)};

        //not deep copied / cloned.
        if(memo.count(n) != 0) return memo[n];

        vector<TreeNode*> res;
        //full binary tree
        //n==1 ruled out
        for(int left_n=1;left_n<=n-2;left_n++){
            int right_n = n-1 - left_n;

            vector<TreeNode*> left = enum_left_right(left_n);
            vector<TreeNode*> right = enum_left_right(right_n);

            for(const auto& l: left)
                for(const auto& r: right){
                    //NOTE: not deep copied / cloned
                    TreeNode* root1 = new TreeNode(0, l, r);
                    res.push_back(root1);
                }
        }

        return memo[n] = res;
    }

    vector<TreeNode*> allPossibleFBT(int n) {
        return enum_left_right(n);
    }
};
