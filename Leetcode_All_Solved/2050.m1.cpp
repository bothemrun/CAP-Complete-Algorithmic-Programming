//m1
//dfs with memo, it's a DAG, so don't need the visited array.
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
    vector<vector<int>> adj_in;//for in-going nodes
    vector<int> memo;

    int dfs_finish(const vector<int>& time, const int& cur){
        if(memo[cur] != notyet) return memo[cur];

        int max_pre = 0;
        for(const int& pre: adj_in[cur])
            max_pre = max(max_pre, dfs_finish(time, pre) );
        return memo[cur] = time[cur] + max_pre;
    }
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        memo.resize(n, notyet);
        adj_in.resize(n);

        for(const vector<int>& e: relations)
            adj_in[e[1] - 1].push_back(e[0] - 1);//to 0-indexed
        
        int max_finish = 0;
        for(int i=0;i<n;i++)
            max_finish = max(max_finish, dfs_finish(time, i) );
        return max_finish;
    }
};
