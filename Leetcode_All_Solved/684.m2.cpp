//m2
//union find by rank + path compression,
//time from O(nlogn) to O(n*1)
#include<assert.h>
class Solution {
public:
    vector<int> set;
    vector<int> rank;
    inline void make_set(const int& n){
        set = vector<int>(n, -1);
        rank = vector<int>(n, 0);
    }
    int set_find(const int& a){
        if(set[a] == (-1))return a;
        return set[a] = set_find(set[a]);
    }
    bool set_join_already_same_set(int a, int b){
        a = set_find(a);
        b = set_find(b);
        if(a == b)return true;

        if(rank[a] < rank[b]) set[a] = b;
        else if(rank[a] > rank[b]) set[b] = a;
        else{
            set[a] = b;
            rank[b]++;
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        make_set(n);

        for(const vector<int>& e: edges){
            if( set_join_already_same_set(e[0]-1, e[1]-1) == true)return e;
        }

        assert(false);
        return vector<int>({-1, -1});
    }
};
