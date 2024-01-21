//m0
//O(n)
#include<stdlib.h>
#include<assert.h>
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
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();

        int ans = 0;
        //[i, j] window
        int j=(-1);
        int cost = 0;
        for(int i=0;i<n;i++){
            //NOTE:
            j = max(j, i-1);

            while(
                j+1<n &&
                cost + abs(s[j+1] - t[j+1]) <= maxCost
            ){
                j++;
                cost += abs(s[j] - t[j]);
            }

            assert(j - (i-1) >= 0);
            ans = max(ans, j - (i-1));

            //update, drop
            //cost -= abs(s[i] - t[i]);
            if(i<=j) cost -= abs(s[i] - t[i]);
        }

        return ans;
    }
};
