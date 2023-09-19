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
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int n = points.size();

        sort(points.begin(), points.end());
        int max_width = 0;
        for(int i=0;i+1<n;i++)
            max_width = max(
                max_width,
                points[i+1][0] - points[i][0]
            );

        return max_width;
    }
};
