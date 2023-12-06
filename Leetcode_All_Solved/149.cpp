//m0
//check lines by division & slope
//may be affected by division precision for some strict testcases.

//O(n^2)

#include<algorithm>
#include<unordered_map>
#include<float.h> //DBL_MAX

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();

        //edge case: n==1
        //int ans = 0;
        int ans = 1;

        for(int i=0;i<n;i++){
            unordered_map<double, int> slope2cnt;
            for(int j=0;j<n;j++)if(i != j){
                double slope;
                if(points[i][0] == points[j][0] )
                    slope = DBL_MAX;
                else
                    slope = (double)(points[i][1] - points[j][1] ) / 
                    (double)(points[i][0] - points[j][0] );

                if(slope2cnt.count(slope) == 0)
                    slope2cnt[slope] = 2;
                else
                    slope2cnt[slope]++;
            }


            for(const auto& [slope, cnt]: slope2cnt){
                ans = max(ans, cnt);
            }
        }

        return ans;
    }
};
