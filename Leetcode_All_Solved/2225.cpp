//O(nlogn)
#define tu2 tuple<int, int>
#include<tuple>
#include<unordered_map>
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
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        
        //player --> (win, loss)
        unordered_map<int, tu2> win_loss;
        for(const vector<int>& m: matches){
            if( win_loss.count(m[0]) == 0)
                win_loss[m[0]] = tu2(1, 0);
            else
                get<0>( win_loss[m[1]] )++;
            
            if( win_loss.count(m[1]) == 0)
                win_loss[m[1]] = tu2(0, 1);
            else
                get<1>( win_loss[m[1]] )++;
        }

        vector<vector<int>> ans(2);
        for(const auto& [player, cnt]: win_loss){
            const auto& [w, l] = cnt;

            if(l == 0) ans[0].push_back(player);
            if(l == 1) ans[1].push_back(player);
        }

        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());
        return ans;
    }
};
