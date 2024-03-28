//m0

//like the implementation of Dijkstra's algorithm by an ordered set.
//we want a priority queue with the update function.
//https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-set-in-stl/

#define tll tuple<long long, long long>
#include<tuple>
#include<set>
#include<unordered_map>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        int n = nums.size();

        //ordered (val, id)
        set<tll> os;
        //id --> val for finding & updating id.
        unordered_map<long long, long long> id2val;
        
        vector<long long> ans(n);
        for(int q=0;q<n;q++){
            long long id = nums[q];
            long long inc = freq[q];

            long long old_val = 0;
            if(id2val.count(id) != 0){
                old_val = id2val[id];

                auto it = os.find( tll(old_val, id) );
                assert(it != os.end());
                os.erase(it);
                //os.erase( tll(old_val, id) );
            }

            id2val[id] = old_val + inc;
            os.insert( tll(old_val + inc, id) );

            const auto& [max_val, max_id] = *(os.rbegin());
            ans[q] = max_val;
        }

        return ans;
    }
};
