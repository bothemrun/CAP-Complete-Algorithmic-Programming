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
#include<unordered_map>
#include<utility>
#include<queue>
class Solution {
private:
    void preorder_level(Node* root, unordered_map<Node*,int>& level_m, int level=0){
        if(root == nullptr)return;
        
        pair<Node*,int> p (root, level);
        level_m.insert(p);
        
        for(Node* child:root->children) preorder_level(child, level_m, level+1);
    }
public:
    vector<vector<int>> levelOrder(Node* root) {
        //get levels
        unordered_map<Node*,int> level_m;
        preorder_level(root, level_m);
        
        //level traversal
        vector<vector<int>> ans;
        vector<int> ans1level;
        queue<Node*> q;
        if(root == nullptr)return ans;
        q.push(root);
        
        int cur_level = 0;
        while(q.size() != 0){
            Node* n = q.front();
            q.pop();
            
            if(level_m.find(n)->second == cur_level+1){
                ans.push_back(ans1level);
                ans1level.clear();
                cur_level++;
            }
            
            ans1level.push_back(n->val);
            for(Node* child:n->children) q.push(child);
        }
        ans.push_back(ans1level);
        
        return ans;
    }
};
