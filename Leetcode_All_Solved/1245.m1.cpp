//m1

//prefix max depth.
//no need for fixed size priority queue.
//Ref: 1245. Tree Diameter votrubac : https://leetcode.com/problems/tree-diameter/solutions/420452/c-with-picture-o-n/


//NOTE: classical pattern: Tree Given By Undirected Graph & No Root:
//- (1) but what's the topmost root? for acyclic graph, any node is.
//- (2) but undirected, how to know parent-child relation? use visited vector, or use anyorder(..., parent).

#include<algorithm>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<vector<int>> al;

    int diameter_by_prefix_max_depth(const int& u, int& diameter, const int& parent=(-1)){

        int prefix_max_depth = 0;
        for(const int& v: al[u])if(v != parent){
            int cur_depth = diameter_by_prefix_max_depth(v, diameter, u);

            diameter = max(diameter, cur_depth + prefix_max_depth);

            prefix_max_depth = max(prefix_max_depth, cur_depth);
        }

        return prefix_max_depth + 1;
    }

    int treeDiameter(vector<vector<int>>& edges) {
        int n = (int)edges.size() + 1;
        al.resize(n);
        for(const vector<int>& e: edges){
            al[e[0]].push_back(e[1]);
            al[e[1]].push_back(e[0]);
        }


        const int root = 0;//or any node
        int diameter = 0;
        diameter_by_prefix_max_depth(root, diameter);
        return diameter;
    }
};
