//m0
//O(QN) with optimization from binary search on the points with pre-sorted x coordinates.

#include<algorithm>
#include<assert.h>

class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        int n = points.size();

        auto cmp_lam = [](const vector<int>& a, const vector<int>& b){
            return a[0] < b[0];
        };
        sort(points.begin(), points.end(), cmp_lam);

        int q = queries.size();
        vector<int> ans(q, 0);
        for(int j=0;j<q;j++){
            int r = queries[j][2];
            int qx = queries[j][0];

            int left = qx - r;
            int right = qx + r;

            int qy = queries[j][1];

            int low = lower_bound(points.begin(), points.end(), vector<int>({left, left}), cmp_lam) - points.begin();

            int high = upper_bound(points.begin(), points.end(), vector<int>({right, right}), cmp_lam) - points.begin();
            high--;

            if(!(low < n)) continue;

            assert(low <= high);

            for(int i=low;i<=high;i++){
                int dx = qx - points[i][0];
                int dy = qy - points[i][1];
                if(dx*dx + dy*dy <= r*r) ans[j]++;
            }
        }

        return ans;
    }
};
