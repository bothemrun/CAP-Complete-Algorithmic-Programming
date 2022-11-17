struct subtree{
    int sum;
    int n;
};
class Solution {
public:
    vector<vector<int>> children;
    struct subtree postorder(int root, const vector<int>& value){
        //non-null node
        
        struct subtree sub = {value[root], 1};
        for(int& child:children[root]){
            struct subtree sub_child = postorder(child, value);
            sub.sum += sub_child.sum;
            sub.n += sub_child.n;
        }
        
        if(sub.sum == 0) sub.n = 0;
        return sub;
    }
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
        children = vector<vector<int>>(nodes, vector<int>());
        for(int i=0;i<nodes;i++){
            if(parent[i] != (-1))
                children[parent[i]].push_back(i);
        }
        
        struct subtree sub = postorder(0, value);
        return sub.n;
    }
};
