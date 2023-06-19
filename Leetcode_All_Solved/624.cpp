#include<algorithm>
#include<utility>
#include<limits.h>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

bool cmp_fn(const pair<int,int>& a, const pair<int,int>& b){
    return a.first < b.first;
}

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        vector<pair<int,int>> min_val_idx;
        vector<pair<int,int>> max_val_idx;
        int m = arrays.size();
        for(int i=0;i<m;i++){
            min_val_idx.push_back(pair<int,int>(arrays[i].front(), i));
            max_val_idx.push_back(pair<int,int>(arrays[i].back(), i));
        }

        pair<int,int> mi = *min_element(min_val_idx.begin(), min_val_idx.end(), cmp_fn);
        pair<int,int> ma = *max_element(max_val_idx.begin(), max_val_idx.end(), cmp_fn);
        //must >= 0
        if(mi.second != ma.second) return ma.first - mi.first;

        min_val_idx[mi.second].first = INT_MAX;
        pair<int,int> mi2 = *min_element(min_val_idx.begin(), min_val_idx.end());
        max_val_idx[ma.second].first = INT_MIN;
        pair<int,int> ma2 = *max_element(max_val_idx.begin(), max_val_idx.end());

        //must >= 0
        return max(
            ma.first - mi2.first,
            ma2.first - mi.first
        );
    }
};
