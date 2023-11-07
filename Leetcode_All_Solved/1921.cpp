//1. sorted in arrival time.
//2. eliminate monsters 1 by 1.
//O(nlogn)

#include<algorithm>
#include<math.h>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();

        vector<int> eta(n);
        for(int i=0;i<n;i++)
            eta[i] = ceil( (double)dist[i] / (double)speed[i] );
        
        sort(eta.begin(), eta.end());

        for(int t=0;t<n;t++){
            if(t >= eta[t]) return t;
        }
        return n;
    }
};
