//O(n) by 1D line sweep instead of O( n*(max log - min log) ).

#define tii tuple<int,int>
#include<tuple>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int n = logs.size();
        vector<tii> line_sweep;

        for(const vector<int>& log: logs){
            line_sweep.push_back(tii( log[0], 1 ));
            line_sweep.push_back(tii( log[1], -1 ));
        }

        //-1 goes before +1
        sort(line_sweep.begin(), line_sweep.end());

        tii max_sweep = tii(0, 0);
        int sweep = 0;
        for(const auto& [pos, delta]: line_sweep){
            sweep += delta;

            max_sweep = max(
                max_sweep,
                tii(sweep, -pos)
            );
        }

        return -get<1>( max_sweep );
    }
};
