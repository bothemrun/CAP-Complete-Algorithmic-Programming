//m01
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
#include<unordered_map>
class Solution {
public:
    Node* dfs(unordered_map<Node*, Node*>& visited_old2new, Node* node){
        if(visited_old2new.count(node) != 0)
            return visited_old2new[node];
        
        class Node* new_node = new Node(node->val);
        visited_old2new[node] = new_node;//NOTE: must be before neighbor dfs
        
        for(class Node* neighbor: node->neighbors)
            new_node->neighbors.push_back( dfs(visited_old2new, neighbor) );
        
        return new_node;
    }

    Node* cloneGraph(Node* node) {
        if(node == nullptr)return nullptr;

        unordered_map<Node*, Node*> visited_old2new;
        return dfs(visited_old2new, node);
    }
};
