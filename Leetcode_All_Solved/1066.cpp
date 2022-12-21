//NOTE: TODO: Bitmask + DP
#include<stdlib.h>//abs()
#include<limits.h>
#include<algorithm>
class Solution {
public:
    int m, n;
    vector<bool> used;
    int min_sum = INT_MAX;

    inline int dist(const vector<int>& a, const vector<int>& b){
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }

    void backtrack(const vector<vector<int>>& workers, const vector<vector<int>>& bikes, const int& w_idx, const int& cur_sum){
        if(w_idx == n){
            //pack
            min_sum = min(min_sum, cur_sum);
            return;
        }

        //NOTE: prune
        if(cur_sum >= min_sum)return;

        for(int b=0;b<m;b++)if(used[b] == false){
            used[b] = true;

            backtrack(
                workers, bikes,
                w_idx+1,
                cur_sum + 
                dist(workers[w_idx], bikes[b])
            );

            used[b] = false;
        }
    }
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        m = bikes.size();
        n = workers.size();

        used = vector<bool>(m, false);
        backtrack(workers, bikes, 0, 0);
        return min_sum;
    }
};
