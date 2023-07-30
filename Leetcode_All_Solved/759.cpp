//m0
//sweep line by tree map. O(nlogn)

/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/
#include<map>
#include<assert.h>
#include<limits.h>

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        map<int,int> sweep_treemap;
        for(const vector<Interval>& vi: schedule){
            for(const Interval& i: vi){
                sweep_treemap[i.start]++;
                sweep_treemap[i.end]--;
            }
        }


        vector<Interval> ans;

        int last_end = INT_MIN;
        int cur_sweep = 0;
        for(const auto& [time, diff]: sweep_treemap){
            bool prev0 = cur_sweep == 0;

            cur_sweep += diff;
            assert(cur_sweep >= 0);

            if(prev0){
                assert(cur_sweep > 0);
                if(last_end != INT_MIN){
                    ans.push_back( Interval(last_end, time) );
                }
            }else{
                if(cur_sweep == 0){
                    last_end = time;
                }
            }
        }

        return ans;
    }
};
