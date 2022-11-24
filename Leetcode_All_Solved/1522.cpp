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
#include<queue>
#include<algorithm>
class cmp_class{
public:
    bool operator()(const int& a, const int& b){
        return a < b;//max heap
    }
};
class Solution {
public:
    int subtree_max_depth_postorder(Node* root, int& max_diameter){
        if(root == nullptr)return 0;
        
        priority_queue<int, vector<int>, cmp_class> max_heap;
        for(Node* child: root->children)
            max_heap.push( subtree_max_depth_postorder(child, max_diameter) );
        
        max_heap.push(0);
        max_heap.push(0);
        int subtree_max1 = max_heap.top();
        max_heap.pop();
        int subtree_max2 = max_heap.top();
        max_heap.pop();
        max_diameter = max(max_diameter, subtree_max1 + subtree_max2);
        
        return subtree_max1 + 1;
    }
    int diameter(Node* root) {
        int max_diameter = 0;
        subtree_max_depth_postorder(root, max_diameter);
        return max_diameter;
    }
};
