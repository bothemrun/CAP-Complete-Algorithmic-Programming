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

class Solution {
private:
    vector<int> ans;
    void postorder_(Node* root){
        if(root==nullptr)return;
        for(Node* c:root->children)
            postorder_(c);
        ans.push_back(root->val);
    }
public:
    vector<int> postorder(Node* root) {
        postorder_(root);
        return ans;
    }
};
