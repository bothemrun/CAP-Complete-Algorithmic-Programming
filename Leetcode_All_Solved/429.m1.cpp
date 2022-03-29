//m1
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
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        //NOTE: variant level order traversal, with current level info
        vector<vector<int>> ans;
        if(root==nullptr)return ans;
        queue<Node*> q;
        q.push(root);
        while(q.size() != 0){
            int level_size = q.size();
            vector<int> ans1level;
            for(int i=0;i<level_size;i++){
                Node* n = q.front();
                q.pop();
                ans1level.push_back(n->val);
                
                for(Node* c:n->children)q.push(c);
            }
            
            ans.push_back(ans1level);
        }
        
        return ans;
    }
};
