//m0
//O(n^2)
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
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();

        long long ans = 0;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++){

                long long bl_x = max(bottomLeft[i][0], bottomLeft[j][0] );
                long long bl_y = max(bottomLeft[i][1], bottomLeft[j][1] );

                long long tr_x = min(topRight[i][0], topRight[j][0] );
                long long tr_y = min(topRight[i][1], topRight[j][1] );

                ans = max(
                    ans,
                    min(tr_x - bl_x, tr_y - bl_y)
                );
            }
        
        return ans*ans;
    }
};
