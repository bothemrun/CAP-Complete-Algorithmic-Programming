//m1
//set count by dfs
#define notyet (-1)
#define max_n 300
#include<algorithm>
class Solution {
public:
    vector<int> set;
    vector<int> cnt;
    vector<vector<int>> adj;

    void dfs(const int& i, const int& root){
        if(set[i] != notyet) return;//visited

        cnt[root]++;
        set[i] = root;

        for(const int& j: adj[i]) dfs(j, root);
    }

    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int n = graph.size();
        set.resize(n, notyet);
        cnt.resize(n, 0);
        adj.resize(n);
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)if(graph[i][j]){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        
        for(const int& mal: initial) dfs(mal, mal);


        int root_malware_cnt[max_n] = {0};
        for(const int& mal: initial) root_malware_cnt[ set[mal] ]++;

        int max_cnt = 0, max_cnt_idx = *min_element(initial.begin(), initial.end());
        for(const int& mal: initial)if( root_malware_cnt[ set[mal] ] == 1){
            if(max_cnt < cnt[ set[mal] ]){
                max_cnt = cnt[ set[mal] ];
                max_cnt_idx = mal;
            }else if(max_cnt == cnt[ set[mal] ])
                max_cnt_idx = min(max_cnt_idx, mal);
        }

        return max_cnt_idx;
    }
};
