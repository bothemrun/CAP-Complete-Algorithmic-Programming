#include<unordered_set>
class Solution {
public:
    vector<vector<int>> adjlist;
    int cnt = 0;
    unordered_set<int> restrict_set;

    void dfs(const int& i, const int& parent){
        if(restrict_set.count(i) != 0)return;
        
        cnt++;

        for(const int& child: adjlist[i])if(child != parent)
            dfs(child, i);
    }

    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        adjlist = vector<vector<int>>(n, vector<int>());
        for(const vector<int>& e: edges){
            adjlist[e[0]].push_back(e[1]);
            adjlist[e[1]].push_back(e[0]);
        }

        for(const int& r: restricted)
            restrict_set.insert(r);

        dfs(0, (-1));
        return cnt;
    }
};
