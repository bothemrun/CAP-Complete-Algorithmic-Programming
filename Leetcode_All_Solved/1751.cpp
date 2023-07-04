//m0
//recursion with memo + binary search preprocessing. O(nk + nlogn)

#define notyet (-1)
#include<algorithm>

class Solution {
public:
    int n;
    int k;
    vector<int> next_compatible;

    vector<vector<int>> memo;
    int enum_compatible(const vector<vector<int>>& events, const int& i, const int& remain){
        if(i==n) return 0;
        if(remain==0) return 0;

        if(memo[i][remain] != notyet) return memo[i][remain];

        //NOTE: choose or not
        return memo[i][remain] = max(
            enum_compatible(events, i+1, remain),
            enum_compatible(events, next_compatible[i], remain-1) + events[i][2]
        );
    }

    int maxValue(vector<vector<int>>& events, int k) {
        this->n = events.size();
        this->k = k;
        next_compatible.resize(n);

        auto cmp = [](const vector<int>& a, const vector<int>& b){
            return a[0] < b[0];
        };
        sort(events.begin(), events.end(), cmp);
        
        for(int i=0;i<n;i++)
            next_compatible[i] = upper_bound(events.begin(), events.end(), vector<int>({events[i][1], -1, -1}), cmp) - events.begin();


        //events count 1-based
        memo.resize(n, vector<int>(k + 1, notyet));
        return enum_compatible(events, 0, k);
    }
};
