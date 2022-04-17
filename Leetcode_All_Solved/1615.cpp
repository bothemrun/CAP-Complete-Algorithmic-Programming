#include<algorithm>
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        if(roads.size() == 0)return 0;
        vector<int> degree(n, 0);
        vector<vector<bool>> adjmat(n, vector<bool>(n, false));
        for(const vector<int>& e:roads){
            degree[e[0]]++;
            degree[e[1]]++;
            adjmat[e[0]][e[1]] = true;
            adjmat[e[1]][e[0]] = true;
        }
        int max_rank = 0;
        for(int i=0;i<n;i++)for(int j=0;j<n;j++)if(i != j){
            if(adjmat[i][j])max_rank = max(max_rank, degree[i] + degree[j] - 1);
            else max_rank = max(max_rank, degree[i] + degree[j]);
        }
        return max_rank;
    }
};
