#include<assert.h>
#include<algorithm>
#include<limits.h>
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();

        vector<long long> idx;
        //NOTE: padding
        idx.push_back(INT_MIN);
        for(int i=0;i<n;i++)if(s[i] == c)
            idx.push_back((long long)i);
        idx.push_back(INT_MAX);


        vector<int> ans(n);
        int idx_low = 0;
        for(long long i=0;i<n;i++){
            int idx_high = idx_low + 1;

            ans[i] = (int)min(
                i - idx[idx_low],
                idx[idx_high] - i
            );

            //update
            if(idx[idx_high] <= i) idx_low++;
        }

        return ans;
    }
};
