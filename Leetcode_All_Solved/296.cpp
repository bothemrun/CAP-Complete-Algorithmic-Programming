//1. dimension reduction
//2.
/*
- The median minimizes the sum of absolute deviations
- https://math.stackexchange.com/a/1024462
- 1. d|x| / dx = sign(x)
- 2. df / dx = sum of sign(x - p_i)
- 3. df / dx = 0, when there are equal numbers of points on the left / right → median, not mean
- 4. if x in far left / right, f goes up. so here it’s the local minima.
*/

//3. O(mnlogmn) due to sorting

#define PII pair<int,int>
#include<utility>
#include<stdlib.h>
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
    int minTotalDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.back().size();
        int dist = 0;//no overflow

        vector<PII> point;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)if(grid[i][j])
                point.push_back(PII(i, j));
        
        int psize = point.size();

        auto cmp_x = [](const PII& a, const PII& b){
            return a.first < b.first;
        };
        sort(point.begin(), point.end(), cmp_x);
        //not a real median
        int median_x = point[psize/2].first;

        for(const auto& [x, y]: point)
            dist += abs(median_x - x);
        

        auto cmp_y = [](const PII& a, const PII& b){
            return a.second < b.second;
        };
        sort(point.begin(), point.end(), cmp_y);
        int median_y = point[psize/2].second;

        for(const auto& [x, y]: point)
            dist += abs(median_y - y);
        
        return dist;
    }
};
