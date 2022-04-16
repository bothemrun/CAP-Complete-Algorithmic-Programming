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

class Solution {
private:
    unordered_map<Node*, Node*> old2new;
    Node* dfs(Node* old){
        if(old2new.count(old) != 0)return old2new.find(old)->second;
        
        Node* new_n = new Node(old->val);
        old2new[old] = new_n;
        
        for(Node* c:old->neighbors)
            new_n->neighbors.push_back(dfs(c));
        return new_n;
    }
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr)return nullptr;
        return dfs(node);
    }
};
