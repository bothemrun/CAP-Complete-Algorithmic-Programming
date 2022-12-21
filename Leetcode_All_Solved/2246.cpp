#include<queue>
class cmp_class{
public:
    bool operator()(const int& a, const int& b){
        return a > b;//min heap, sink down
    }
};
class Solution {
public:
    vector<vector<int>> children;
    int max_path = 0;
    inline void push(priority_queue<int, vector<int>, cmp_class>& min_heap, const int& depth){
        min_heap.push(depth);
        if(min_heap.size() >= 3)min_heap.pop();
    }
    int tree_diameter(const int& root, const string& s){
        priority_queue<int, vector<int>, cmp_class> min_heap;
        for(const int& child: children[root]){
            //NOTE: cannot prune
            int child_depth = tree_diameter(child, s);
            if(s[child] == s[root]) child_depth = 0;
            
            push(min_heap, child_depth);
        }

        int this_depth = 0; //NOTE: init: int this_depth;
        int this_path = 0;
        //NOTE: ok for 0~2 children
        while(min_heap.size() != 0){
            if(min_heap.size() == 1)
                this_depth = min_heap.top();

            this_path += min_heap.top();
            min_heap.pop();
        }

        max_path = max(max_path, this_path);

        return this_depth + 1;
    }
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        children = vector<vector<int>>(n, vector<int>());
        for(int i=0;i<n;i++)if(parent[i] != (-1))
            children[ parent[i] ].push_back(i);
        
        tree_diameter(0, s);
        return max_path + 1;//I count by edges

    }
};
