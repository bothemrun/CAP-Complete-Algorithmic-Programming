//m1
//find connected components by union find by rank with path compression, amortized in O(1)
#define ROOT (-1)
#include<unordered_map>
class Solution {
public:
    vector<int> set;
    vector<int> rank;
    inline void make_set(const int& n){
        set = vector<int>(n, ROOT);
        rank = vector<int>(n, 0);
    }
    int set_find(const int& a){
        if(set[a] == ROOT)return a;
        return set[a] = set_find(set[a]);
    }
    void set_join(int a, int b){
        a = set_find(a);
        b = set_find(b);
        if(a == b)return;

        if(rank[a] < rank[b]) set[a] = b;
        else if(rank[a] > rank[b]) set[b] = a;
        else{
            set[a] = b;
            rank[b]++;
        }
    }
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        //NOTE: make connected components
        int n = source.size();
        make_set(n);
        for(const vector<int>& e: allowedSwaps)
            set_join(e[0], e[1]);
        
        vector<vector<int>> connected_component(n);
        for(int i=0;i<n;i++)
            connected_component[ set_find(i) ].push_back(i);
        

        //NOTE: compute hamming distance
        int hamming = 0;
        for(const vector<int>& component: connected_component)if(component.size() != 0){
            unordered_map<int,int> val2cnt;
            for(const int& idx: component)
                val2cnt[ source[idx] ]++;
            
            for(const int& idx: component){
                if(val2cnt.count( target[idx] ) == 0) hamming++;
                else if(--val2cnt[ target[idx] ] == 0)
                    val2cnt.erase(target[idx]);
            }
        }

        return hamming;
    }
};
