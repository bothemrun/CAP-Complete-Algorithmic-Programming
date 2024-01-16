//m0
//O(nlogn) line sweep
//by the fact that two intervals of the same person don't intersect.

#define tu2 tuple<int, int>
#include<tuple>
#include<assert.h>
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
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        int n = slots1.size();

        vector<tu2> line_sweep;
        auto push = [&line_sweep](const vector<vector<int>>& slots){
            for(const vector<int>& i: slots){
                line_sweep.push_back( tu2(i[0], 1) );
                line_sweep.push_back( tu2(i[1], -1) );
            }
        };

        for(const vector<vector<int>>& slots: {slots1, slots2})
            push(slots);

        //(1) for 2 people, for the same position, (-1) goes before +1.
        //(2) for the same person, no [pos, -1] [pos, 1] for the same position pos.
        sort(line_sweep.begin(), line_sweep.end());


        const int people = 2;
        int sweep = 0;
        int start = INT_MAX;
        for(const auto& [pos, delta]: line_sweep){
            sweep += delta;

            if(sweep == people){
                assert(delta == 1);
                start = pos;
            }else if(delta == (-1) && sweep == people-1){
                int len = pos - start;

                if(len >= duration)
                    return vector<int>({start, start + duration});
            }
        }

        return vector<int>();
    }
};
