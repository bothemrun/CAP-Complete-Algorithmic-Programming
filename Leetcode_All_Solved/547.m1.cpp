//m1
#define root (-1)
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> set;
    vector<int> rank;
    int set_cnt;
    inline void make_set(const int& size){
        set.resize(size, root);
        rank.resize(size, 1);
        set_cnt = size;
    }
    int set_find(const int& a){
        if(set[a] == root) return a;
        return set[a] = set_find(set[a]);
    }
    inline void set_join(int a, int b){
        a = set_find(a);
        b = set_find(b);
        if(a == b) return;

        set_cnt--;

        if(rank[a] < rank[b]) set[a] = b;
        else if(rank[a] > rank[b]) set[b] = a;
        else{
            set[a] = b;
            rank[b]++;
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        make_set(n);

        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)if(isConnected[i][j])
                set_join(i, j);
        
        return set_cnt;
    }
};
