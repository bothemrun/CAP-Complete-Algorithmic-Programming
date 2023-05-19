//m1
//uva 10158 war
//union find by rank with path compression in amortized O(1)
#define ROOT (-1)
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

enum{
    Friend,
    Enemy,
    Unknown
};
class Solution {
public:
    int n;
    vector<int> set;
    vector<int> rank;
    inline void make_set(const int& size){
        set.resize(size, ROOT);
        rank.resize(size, 1);
    }
    int set_find(const int& a){
        if(set[a] == ROOT) return a;
        return set[a] = set_find(set[a]);
    }
    inline void set_join(int a, int b){
        a = set_find(a);
        b = set_find(b);
        if(a == b) return;

        if(rank[a] < rank[b]){
            set[a] = b;
        }else if(rank[b] > rank[b]){
            set[b] = a;
        }else{
            set[a] = b;
            rank[b]++;
        }
    }
    inline void set_relation(const int& a, const int& b, const int& rel){
        if(rel == Friend){
            set_join(a, b);
            set_join(a+n, b+n);
        }else if(rel == Enemy){
            set_join(a, b+n);
            set_join(a+n, b);
        }
    }
    inline int relation(const int& a, const int& b){
        if(set_find(a) == set_find(b)) return Friend;
        else if(set_find(a) == set_find(b+n)) return Enemy;
        else return Unknown;

    }
    bool isBipartite(vector<vector<int>>& graph) {
        n = graph.size();
        make_set(n * 2);//NOTE: for uva war

        for(int i=0;i<n;i++){
            for(const int& j: graph[i]){
                if(relation(i, j) == Friend) return false;
                set_relation(i, j, Enemy);
            }
        }

        return true;
    }
};
