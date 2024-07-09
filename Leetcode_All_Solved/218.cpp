//m0
//[A] line sweep


//[B] to deduplicate consecutive equal heights like testcase 2,

//1. process deltas with the same positions in a row.
//2. use a tree map of positions --> vector for the same position.


//[C] not a typical line sweep (sum of sweep deltas), but max of the buildings currently on:

//1. use a tree multiset for efficiently erasing & finding max. --> as the typical int sweep.


//O(nlogn)

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

        map<int, vector<int>> line_sweep;
        for(const vector<int>& b: buildings){
            line_sweep[b[0]].push_back(b[2]);
            line_sweep[b[1]].push_back(-b[2]);
        }


        vector<vector<int>> ans;

        multiset<int> sweep;
        for(const auto& [pos, heights]: line_sweep){
            for(const int& h: heights){
                if(h>0){
                    sweep.insert(h);
                }else{
                    //erase(val) erases all instances with val
                    sweep.erase(sweep.find( -h ));
                }
            }

            int skyline = 0;
            if(sweep.size()) skyline = *sweep.rbegin();
            if(ans.size()==0 || ans.back()[1] != skyline){
                ans.push_back(vector<int>({ pos, skyline }));
            }
        }

        return ans;
    }
};
