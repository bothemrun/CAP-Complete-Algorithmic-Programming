/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
#include<algorithm>
class Solution {
private:
    int max_depth = 0;
    void preorder(Node* root, int depth=1){
        max_depth = max(max_depth, depth);
        for(Node* c:root->children)
            preorder(c, depth+1);
    }
public:
    int maxDepth(Node* root) {
        if(root == nullptr)return 0;
        preorder(root);
        return max_depth;
    }
};
