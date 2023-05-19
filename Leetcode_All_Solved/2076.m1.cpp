//m1
//why can't use uva war ? because that's used in bipartition.

//NOTE: use bitset to check restrictions, instead of traversing all restrictions one by one.
//also use union find by rank with path compression in amortized O(1), as in method 0.
#define ROOT (-1)
#define max_n 1000
#include<bitset>

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

    vector<bitset<max_n>> ban;
    vector<bitset<max_n>> set_bits;

    inline void make_set(const int& size){
        set.resize(size, ROOT);
        rank.resize(size, 1);
    }
    int set_find(const int& a){
        if(set[a] == ROOT) return a;
        return set[a] = set_find(set[a]);
    }
    inline void bitset_merge(const int& child, const int& parent){
        set[child] = parent;

        ban[parent] |= ban[child];
        set_bits[parent] |= set_bits[child];
    }
    inline void set_join(int a, int b){
        a = set_find(a);
        b = set_find(b);
        if(a == b) return;

        if(rank[a] < rank[b]) bitset_merge(a, b);
        else if(rank[a] > rank[b]) bitset_merge(b, a);
        else{
            bitset_merge(a, b);
            rank[b]++;
        }
    }

    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        make_set(max_n); //make_set(n);

        ban.resize(max_n, bitset<max_n>() );
        for(const vector<int>& b: restrictions){
            ban[ b[0] ][ b[1] ] = 1;
            ban[ b[1] ][ b[0] ] = 1;
        }

        set_bits.resize(max_n, bitset<max_n>());
        for(int i=0;i<n;i++) set_bits[i][i] = 1;


        vector<bool> ans;
        for(const vector<int>& f: requests){
            int f1 = set_find(f[0]);
            int f2 = set_find(f[1]);

            if(
                ( ban[f1] & set_bits[f2] ).any() ||
                ( ban[f2] & set_bits[f1] ).any()
            ) ans.push_back(false);
            else{
                ans.push_back(true);
                set_join(f[0], f[1]);
            }
        }
        return ans;
    }
};
