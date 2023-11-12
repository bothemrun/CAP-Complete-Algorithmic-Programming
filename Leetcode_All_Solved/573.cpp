#include<stdlib.h>
#include<limits.h>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        int n = nuts.size();

        int dist = 0;//no overflow

        int min_s2nut_minus_t2nut = INT_MAX;

        for(int i=0;i<n;i++){
            int r = nuts[i][0];
            int c = nuts[i][1];

            int s2nut = abs(r - squirrel[0]) + abs(c - squirrel[1]);
            int t2nut = abs(r - tree[0]) + abs(c - tree[1]);

            dist += 2 * t2nut;

            min_s2nut_minus_t2nut = min(
                min_s2nut_minus_t2nut,
                s2nut - t2nut
            );
        }

        return dist + min_s2nut_minus_t2nut;
    }
};
