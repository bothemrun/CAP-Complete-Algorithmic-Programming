//m0
//O(nlogn) due to sorting.
//but can be improved to O(n) without sorting by hash set.

#include<unordered_map>
#include<unordered_set>
#include<assert.h>
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
    bool isReflected(vector<vector<int>>& points) {
        unordered_map<int, unordered_set<int>> y2x_set;
        for(const vector<int>& p: points)
            y2x_set[p[1]].insert(p[0]);
        
        unordered_map<int, vector<int>> y2x;
        for(const auto& [y, x_set]: y2x_set){
            for(const int& x: x_set)
                y2x[y].push_back(x);
            
            sort(y2x[y].begin(), y2x[y].end());
        }

        assert(y2x.size());
        auto it = y2x.begin();
        double reflect = ( (double)it->second.front() + (double)it->second.back() ) / 2.0;

        for(const auto& [y, xv]: y2x){
            int n = xv.size();
            int i=0, j=n-1;
            while(i<=j){
                double x1 = xv[i++];
                double x2 = xv[j--];
                if( (x1+x2)/2.0 != reflect)
                    return false;
            }
        }

        return true;
            
        
    }
};
