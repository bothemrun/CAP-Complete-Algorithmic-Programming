//O(n)
#define max_n 100
#include<assert.h>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        bool has_indegree[max_n] = {0};
        int has_indegree_cnt = 0;

        for(const vector<int>& e: edges){
            if(has_indegree[ e[1] ] == false)
                has_indegree_cnt++;

            has_indegree[ e[1] ] = true;
        }

        if(has_indegree_cnt != n-1) return (-1);
        for(int i=0;i<n;i++)if(has_indegree[i] == false)
            return i;

        assert(false);
        return (-2);
    }
};
