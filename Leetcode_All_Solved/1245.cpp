//NOTE: classical pattern: Tree Given By Undirected Graph & No Root:
//- (1) but what's the topmost root? for acyclic graph, any node is.
//- (2) but undirected, how to know parent-child relation? use visited vector, or use anyorder(..., parent).

#include<algorithm>
#include<queue>
class cmp_class{
public:
    bool operator()(const int& a, const int& b){
        return a > b;//min heap, sink down
    }
};

class Solution {
public:
    int n;
    const int topmost_root = 0;
    vector<vector<int>> adjlist;
    int diameter = 0;

    void push(priority_queue<int, vector<int>, cmp_class>& min_heap2, const int& x){
        min_heap2.push(x);

        if(min_heap2.size() >= 3) min_heap2.pop();
    }

    int tree_diameter_depth(const int& cur, const int& parent){
        priority_queue<int, vector<int>, cmp_class> min_heap2;
        for(const int& child: adjlist[cur])if(child != parent){
            push( min_heap2, tree_diameter_depth(child, cur) );
        }

        //NTOE: ok for no children
        int max_child_depth = 0;
        int path = 0;
        while(min_heap2.size() != 0){
            int depth = min_heap2.top();
            min_heap2.pop();

            path += depth;

            if(min_heap2.size() == 0)
                max_child_depth = depth;
        }

        diameter = max(diameter, path);

        return max_child_depth + 1;
    }

    int treeDiameter(vector<vector<int>>& edges) {
        n = edges.size() + 1;
        adjlist = vector<vector<int>>(n, vector<int>());
        for(const vector<int>& e: edges){
            adjlist[ e[0] ].push_back(e[1]);
            adjlist[ e[1] ].push_back(e[0]);
        }

        tree_diameter_depth(topmost_root, (-1));
        return diameter;
    }
};
