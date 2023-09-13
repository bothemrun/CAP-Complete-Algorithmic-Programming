//m0
//sweep line. O(nlogn)

#define PII pair<int,int>
#include<algorithm>
#include<utility>
#include<assert.h>

class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<PII> sweep_line;
        for(const vector<int>& car: nums){
            sweep_line.push_back( PII(car[0], 1) );
            sweep_line.push_back( PII(car[1], -1) );
        }

        auto cmp_lam = [](const PII& a, const PII& b){
            if(a.first != b.first) return a.first < b.first;
            return a.second > b.second;
            //[4, 4]
        };
        sort(sweep_line.begin(), sweep_line.end(), cmp_lam);
        //if a car's start & end intersect at exactly 1 point, eg., [4, 4]


        int sweep = 0;
        int point = 0;

        const int no_last0_pos = (-1);
        int last0_pos = no_last0_pos;

        for(const auto& [pos, delta]: sweep_line){
            int old_sweep = sweep;
            sweep += delta;
            assert(old_sweep >= 0 && sweep >= 0);
            if(old_sweep == 0){
                assert(sweep == 1);

                last0_pos = pos - 1;
            }
            if(sweep == 0){
                assert(old_sweep == 1);

                assert(last0_pos != no_last0_pos);
                point += pos - last0_pos;
                last0_pos = no_last0_pos;
            }
        }

        return point;
    }
};
