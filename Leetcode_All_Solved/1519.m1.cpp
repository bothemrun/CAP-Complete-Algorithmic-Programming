//m1
//greatly optim: don't copy hash maps for each node.
#define alphabet 26
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<vector<int>> adj;
    vector<int> ans;

    void postorder_ignore_sibling(const string& labels, vector<int>& char2cnt, const int& root, const int& parent=(-1)){
        
        int sibling = char2cnt[ labels[root] - 'a' ];
        
        for(const int& child: adj[root])if(child != parent)
            postorder_ignore_sibling(labels, char2cnt, child, root);
        

        char2cnt[ labels[root] - 'a' ]++;
        int subtree = char2cnt[ labels[root] - 'a' ] - sibling;
        ans[root] = subtree;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        adj.resize(n);
        for(const vector<int>& e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        ans.resize(n);

        vector<int> char2cnt(alphabet, 0);
        postorder_ignore_sibling(labels, char2cnt, 0);

        return ans;
    }
};
