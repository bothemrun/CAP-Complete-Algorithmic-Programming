//O(nlogn)
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
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        sort(points.begin(), points.end());

        int n = points.size();
        int ans = 0;

        int i=0;
        while(i<n){
            ans++;

            //no overflow
            int next_cover = points[i][0] + w;

            for(;i<n;i++)if(points[i][0] > next_cover) break;
        }

        return ans;
    }
};
