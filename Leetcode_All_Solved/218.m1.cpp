//m1
//[A] line sweep
//line sweep implemented by sorting.


//[B] to deduplicate consecutive equal heights like testcase 2,

//1. process deltas with the same positions in a row.
//2. use a tree map of positions --> vector for the same position.


//[C] not a typical line sweep (sum of sweep deltas), but max of the buildings currently on:

//1. use a tree multiset for efficiently erasing & finding max. --> as the typical int sweep.


//O(nlogn)

#define tii tuple<int, int>
#include<map>
#include<set>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int n = buildings.size();

        vector<tii> line_sweep(2*n);
        for(int i=0;i<n;i++){
            const auto& b = buildings[i];

            line_sweep[2*i] = tii(b[0], b[2]);
            //not b[1] + 1
            line_sweep[2*i+1] = tii(b[1], -b[2]);
        }

        sort(line_sweep.begin(), line_sweep.end());


        vector<vector<int>> ans;

        multiset<int> sweep_h_cur_on;

        int i=0, m = line_sweep.size();
        while(i<m){
            const auto [pos, _] = line_sweep[i];

            //go thru the same pos
            int j;
            for(j=i;j<m && get<0>(line_sweep[j]) == pos;j++){
                const auto [_, h] = line_sweep[j];

                if(h>0){
                    sweep_h_cur_on.insert(h);
                }else{
                    //erase(val) erases all instances with val
                    sweep_h_cur_on.erase( sweep_h_cur_on.find( -h ) );
                }
            }

            //update
            i = j;


            int skyline = 0;
            if(sweep_h_cur_on.size()) skyline = *sweep_h_cur_on.rbegin();


            if(ans.size()==0 || ans.back()[1] != skyline){
                ans.push_back(vector<int>({pos, skyline}));
            }
        }

        return ans;
    }
};
