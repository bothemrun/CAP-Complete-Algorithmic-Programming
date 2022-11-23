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
#include<unordered_set>
class Solution {
public:
    Node* findRoot(vector<Node*> tree) {
        unordered_set<Node*> parent_set, child_set;
        for(Node* parent: tree){
            parent_set.insert(parent);
            for(Node* child: parent->children)
                child_set.insert(child);
        }
        
        for(unordered_set<Node*>::iterator it=parent_set.begin();it != parent_set.end();it++){
            if(child_set.count(*it) == 0)return *it;
        }
        return nullptr;
    }
};
