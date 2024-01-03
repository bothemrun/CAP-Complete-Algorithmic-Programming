//can be done in 2 methods:
//1. sort in the end
//2. tree map
//both in O(nlogn)

#include<map>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    //no overflow
    map<int, int> treemap;

    inline void accum(const vector<vector<int>>& items){
        for(const vector<int>& i: items)
            treemap[ i[0] ] += i[1];
    }

    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        accum(items1);
        accum(items2);

        vector<vector<int>> ans;
        for(const auto& [k, v]: treemap)
            ans.push_back( vector<int>({k, v}) );
        return ans;
    }
};
