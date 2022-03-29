class Solution {
private:
    void dag_dfs(const vector<vector<int>>& graph, vector<vector<int>>& ans, vector<int>& cur_path, int now, const int& dest){
        if(now == dest){
            ans.push_back(cur_path);
            return;
        }
        
        for(int child:graph[now]){
            cur_path.push_back(child);
            dag_dfs(graph, ans, cur_path, child, dest);
            cur_path.pop_back();
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> cur_path {0};
        vector<vector<int>> ans;
        dag_dfs(graph, ans, cur_path, 0, graph.size()-1);
        return ans;
    }
};
