//m0
//NOTE: preorder/postorder marking may be more powerful than binary lifting.
//it gives us the subtree information.

//consider the problem:
//given a tree, we conceal part of the nodes. we only know the number of nodes from the the node to its ancestor.
//return if a node is the (k'th) ancestor of another node.

//Thinking Process:
//(1) go up k levels from the node's level.
//(2) then which one is the node's ancestor in that level?

//(3) maintain a set for each node containing its descendants/ancestors ?? too costly.
//(4) use preorder's visiting order for marking.
//(5) among preorder marking < the node's marking, the largest marking is the ancestor.
//(5.1) maybe similar for postorder marking.

//inpired by: Aranne:
//https://leetcode.com/problems/kth-ancestor-of-a-tree-node/solutions/689481/beats-97-dfs-binary-search-detailed/

//NOTE: so why can't we just jump k upwards by the parent info?
//worst case: the whole tree has only 1 branch. then each call needs O(n) --> O(1e8) TLE.

#include<algorithm>
#include<assert.h>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class TreeAncestor {
public:
    vector<int> node2level;
    vector<vector<int>> level2preorder;

    vector<int> node2preorder;
    vector<int> preorder2node;

    vector<vector<int>> al;
    const int ROOT = 0;

    void preorder_marking(const int& node, int& preorder_mark, const int& level){

        preorder2node[preorder_mark] = node;
        node2preorder[node] = preorder_mark;

        node2level[node] = level;
        //NOTE: automatically sorted.
        level2preorder[level].push_back( preorder_mark );

        preorder_mark++;

        for(const int& child: al[node]){
            preorder_marking(child, preorder_mark, level + 1);
        }
    }

    TreeAncestor(int n, vector<int>& parent) {
        al.resize(n);
        for(int i=0;i<n;i++)if(parent[i] != (-1))
            al[ parent[i] ].push_back(i);
        
        node2level.resize(n);
        level2preorder.resize(n); //for ease

        node2preorder.resize(n);
        preorder2node.resize(n);

        int preorder_mark = 0;
        preorder_marking(ROOT, preorder_mark, 0);
    }
    
    int getKthAncestor(int node, int k) {
        int this_level = node2level[ node ];
        int ancestor_level = this_level - k;
        if(ancestor_level < 0) return (-1);

        int this_preorder = node2preorder[node];
        const auto& preorder = level2preorder[ ancestor_level ];
        assert(preorder.size());
        auto it = lower_bound(preorder.begin(), preorder.end(), this_preorder);
        assert(it != preorder.begin());
        return preorder2node[ *prev(it) ];
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
