//1. how to represent to state of way 2 on subtrees?
// not by 2^bit_shift, but by bit_shift
// or TLE, MLE.

//2. O(n * log(max coin) ) dp
//O(log(max coin)) = O(log_2(1e4)) <= 14

#define max_bit_shift 14

#define notyet (-1)
#include<algorithm>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<vector<int>> al;
    vector<vector<int>> memo;
    const int top_root = 0;

    int enum_bit_shift(const vector<int>& coins, const int& k, int u, int pre=(-1), int bit_shift=0){
        //pruning: all subtree 0
        if(bit_shift >= max_bit_shift) return 0;

        if(memo[u][bit_shift] != notyet) return memo[u][bit_shift];

        int way1 = coins[u] / (1<<bit_shift) - k;
        int way2 = coins[u] / (1<<(bit_shift + 1));
        //ok for leaf.
        for(const int& v: al[u])if(v != pre){
            way1 += enum_bit_shift(coins, k, v, u, bit_shift);

            way2 += enum_bit_shift(coins, k, v, u, bit_shift + 1);
        }

        return memo[u][bit_shift] = max(way1, way2);
    }

    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        int n = coins.size();
        al.resize(n);
        for(const vector<int>& e: edges){
            al[e[0]].push_back(e[1]);
            al[e[1]].push_back(e[0]);
        }

        memo.resize(n, vector<int>(max_bit_shift + 1, notyet));
        return enum_bit_shift(coins, k, top_root);
    }
};
