//O(nlogn) by 1D line sweep

#define tii tuple<int,int>
#include<tuple>
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
    int countDays(int days, vector<vector<int>>& meetings) {
        int n = meetings.size();
        vector<tii> line_sweep(2*n);
        for(int i=0;i<n;i++){
            line_sweep[2*i] = tii(meetings[i][0], 1);
            line_sweep[2*i+1] = tii(meetings[i][1] + 1, -1);
        }

        auto cmp = [](const tii& a, const tii& b){
            if( get<0>(a) != get<0>(b) )
                return get<0>(a) < get<0>(b);
            else
                return get<1>(a) > get<1>(b);
            //+1 before -1
        };
        sort(line_sweep.begin(), line_sweep.end(), cmp);

        
        int meet = 0;
        int last_on = INT_MAX;
        int sweep = 0;
        for(const auto& [pos, delta]: line_sweep){
            int old_sweep = sweep;
            sweep += delta;

            if(old_sweep==0){
                //turned on
                last_on = pos;
            }else if(sweep == 0){
                //turned off
                meet += (pos-1) - (last_on-1);
            }
        }

        return days - meet;
    }
};
