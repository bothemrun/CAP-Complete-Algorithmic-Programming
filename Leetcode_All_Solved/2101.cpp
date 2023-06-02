#define max_n 100
#define p2(x) ((long long)(x) * (long long)(x))
#include<algorithm>
class Solution {
public:
    vector<vector<int>> adj;
    void dfs(const int& i, bool visited[], int& det){
        if(visited[i]) return;
        visited[i] = true;

        det++;
        for(const int& j: adj[i]) dfs(j, visited, det);
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        adj.resize(n);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)if(i != j){
                if( p2(bombs[i][0]-bombs[j][0]) + p2(bombs[i][1]-bombs[j][1]) <= p2(bombs[i][2]) )
                    adj[i].push_back(j);
            }
        
        int max_det = 0;
        for(int i=0;i<n;i++){
            bool visited[max_n] = {0};
            int det = 0;
            dfs(i, visited, det);
            max_det = max(max_det, det);
        }
        return max_det;
    }
};
