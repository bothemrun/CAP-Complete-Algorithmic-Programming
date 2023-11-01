//m1
//O(n) without sorting

#include<unordered_map>
#include<unordered_set>
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
    bool isReflected(vector<vector<int>>& points) {
        unordered_map<int, unordered_set<double>> y2x;
        for(const vector<int>& p: points)
            y2x[p[1]].insert((double)p[0]);
        
        assert(y2x.size());
        auto xset = y2x.begin()->second;
        
        double min_x = *(xset.begin());
        double max_x = min_x;
        for(const double& x: xset){
            min_x = min(min_x, x);
            max_x = max(max_x, x);
        }

        double reflect = max_x + min_x;

        for(const auto& [y, xset]: y2x){
            for(const double& x: xset){
                double x2 = reflect - x;

                if(xset.count(x2) == 0)
                    return false;
            }
        }

        return true;
    }
};
