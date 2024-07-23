//m0

//[A] Dimension Reduciton: fix 1 A:
//1. so only points to its right matters --> pre-sort.
//2. now the criterion for x-axis must hold.


//[B] the remaining criterion is the y-axis.
//1. no other points in between A & B --> 
//2. no other y values in between A & B's y values.

//3. sweep from left to right, if a point is on B's left --> the remaining criterion is the y-axis. --> B's y value must be below that point's y.
//4. so the bound is actually monotonic.

//O(n^2)
#include<functional>
class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        //x increasingly, y decreasingly
        //edge case: B at (10, 10), (10, 5), (10, 1)
        function<bool(const vector<int>&, const vector<int>&)> cmp = [](const vector<int>& a, const vector<int>& b){
            if(a[0] != b[0]) return a[0] < b[0];
            return a[1] > b[1];
        };
        sort(points.begin(), points.end(), cmp);

        int ans = 0;//no overflow
        for(int i=0;i<n;i++){
            int ay = points[i][1];

            int bound = INT_MIN;
            for(int j=i+1;j<n;j++){
                int by = points[j][1];

                if(ay >= by){
                    if(by > bound) ans++;

                    bound = max(bound, by);
                }
            }
        }
        return ans;
    }
};
