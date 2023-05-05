//m0
//union find by rank + path compression in O(1)
#define Root (-1)
#define max_n 300
#include<algorithm>
class Solution {
public:
    vector<int> set;
    vector<int> rank;
    vector<int> cnt;
    inline void make_set(const int& n){
        set.resize(n, Root);
        rank.resize(n, 1);
        cnt.resize(n, 1);
    }
    int set_find(const int& a){
        if(set[a] == Root)return a;
        else return set[a] = set_find(set[a]);
    }
    inline void set_join(int a, int b){
        a = set_find(a);
        b = set_find(b);
        if(a == b)return;

        if(rank[a] < rank[b]){
            set[a] = b;
            cnt[b] += cnt[a];
        }else if(rank[a] > rank[b]){
            set[b] = a;
            cnt[a] += cnt[b];
        }else{
            set[a] = b;
            cnt[b] += cnt[a];
            rank[b]++;
        }
    }
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int n = graph.size();
        make_set(n);
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)if(graph[i][j])
                set_join(i, j);
        
        int root_malware_cnt[max_n] = {0};
        for(const int& mal: initial) root_malware_cnt[ set_find(mal) ]++;

        int max_cnt = 0, max_cnt_idx = *min_element(initial.begin(), initial.end());
        for(const int& mal: initial){
            int root = set_find(mal);
            if(root_malware_cnt[root] != 1) continue;

            if(max_cnt < cnt[root]){
                max_cnt = cnt[root];
                max_cnt_idx = mal;
            }else if(max_cnt == cnt[root])
                max_cnt_idx = min(max_cnt_idx, mal);
        }

        return max_cnt_idx;
    }
};
