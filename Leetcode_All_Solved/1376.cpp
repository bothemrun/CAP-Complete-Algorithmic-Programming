#include<limits.h>
class Solution {
private:
    void parent_represent_build_tree(const vector<int>& parent, const int& n, vector<vector<int>>& children, const int& root){
        //for(int i=0;i<n;i++) children[parent[i]].push_back(i);
        for(int i=0;i<n;i++)if(i != root)children[parent[i]].push_back(i);
    }
    int longest_path_dfs(const vector<vector<int>>& children, int i, const vector<int>& informTime){
        if(children[i].size() == 0)return 0;
        
        int max_subtree_len = INT_MIN;
        for(int c:children[i]) max_subtree_len = max(max_subtree_len, longest_path_dfs(children, c, informTime));
        return informTime[i] + max_subtree_len;
    }
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        //build tree
        vector<vector<int>> children (n, vector<int>());
        parent_represent_build_tree(manager, n, children, headID);
        
        //longest path
        return longest_path_dfs(children, headID, informTime);
    }
};
