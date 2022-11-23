//m1
//optim space from O(n) to O(1) by XOR.
//XOR: (1)multiplication == division (2)so A^A == I (3)identity == 0
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
#include<assert.h>
class Solution {
public:
    Node* findRoot(vector<Node*> tree) {
        int product_parents = 0, product_children = 0;
        for(Node* parent: tree){
            product_parents ^= parent->val;
            for(Node* child: parent->children)
                product_children ^= child->val;
        }
        int parent_val = product_parents ^ product_children;
        
        for(Node* parent: tree)if(parent->val == parent_val)
            return parent;
        
        assert(false);
        return nullptr;
    }
};
