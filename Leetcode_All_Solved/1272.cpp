//m0
//O(nlogn) line sweep by sorting
//can be done in O(n) by simple array method,
//but this is more general for a list of intervals to be removed.

#define tii tuple<int, int>
#include<tuple>
#include<limits.h>
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
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        
        vector<tii> line_sweep;

        for(const vector<int>& i: intervals){
            line_sweep.push_back(tii(i[0], 1));
            line_sweep.push_back(tii(i[1], -1));
        }

        line_sweep.push_back(tii( toBeRemoved[0], -1 ));
        line_sweep.push_back(tii( toBeRemoved[1], 1 ));

        auto cmp = [](const tii& a, const tii& b){
            const auto& [a_pos, a_delta] = a;
            const auto& [b_pos, b_delta] = b;
            if(a_pos != b_pos) return a_pos < b_pos;
            else return a_delta < b_delta;
            //(-1) before +1
            //since intervals are disjoint.
            //hence we don't need to worry about deltas +1 / -1 at the same pos.
            //we only need to worry about deltas at the same pos for a removal & an additive interval.
        };

        sort(line_sweep.begin(), line_sweep.end(), cmp);


        vector<vector<int>> ans;

        int sweep = 0;
        int no_last_up = INT_MIN;
        int last_up = no_last_up;
        for(const auto& [pos, delta]: line_sweep){
            int old_sweep = sweep;
            sweep += delta;

            if(sweep == 1 && old_sweep == 0){
                last_up = pos;
            }else if(sweep == 0 && old_sweep == 1){
                assert(last_up != no_last_up);
                ans.push_back(vector<int>({ last_up, pos }));

                last_up = no_last_up;
            }
        }

        return ans;
    }
};
