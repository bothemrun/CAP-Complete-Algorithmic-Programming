//m2
//optim space from O(n) to O(1) by XOR.
//XOR: (1)multiplication == division (2)so A^A == I (3)identity == 0
//why turn Node* into long long? why not directly do XOR on Node* ?
//because C++ operators like + - * / ^ only works on C++ defined types. 
//And for user-defined types we need to override operators, just like operator+ for the polynomial class.
//But luckily, addresses are just 64-bit or 32-bit numerical values.
//So we can turn addresses into long long, so we can utilize C++ operator ^ on C++ defined type long long.

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
        long long product_parents = 0;
        long long product_children = 0;
        for(Node* parent: tree){
            product_parents ^= (long long)parent;
            for(Node* child: parent->children)
                product_children ^= (long long)child;
        }
        return (Node*)(product_parents ^ product_children);
    }
};
