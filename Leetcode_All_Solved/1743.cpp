#define end_indegree 1

#include<unordered_map>
#include<limits.h>
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
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> al;
        unordered_map<int, int> indegree;

        for(const vector<int>& p: adjacentPairs){
            al[p[0]].push_back(p[1]);
            al[p[1]].push_back(p[0]);

            indegree[p[0]]++;
            indegree[p[1]]++;
        }

        int start = INT_MAX;
        for(const auto& [u, ind]: indegree)if(indegree[u] == end_indegree){
            start = u;
            break;
        }
        assert(start != INT_MAX);


        vector<int> ans;
        int pre = INT_MAX;
        int cur = start;
        while(true){
            ans.push_back(cur);
            cout<<cur<<endl;

            if(cur != start && al[cur].size() == end_indegree)
                break;

            for(const int& v: al[cur])if(v != pre){
                pre = cur;
                cur = v;
                break;
            }
        }

        return ans;
    }
};
