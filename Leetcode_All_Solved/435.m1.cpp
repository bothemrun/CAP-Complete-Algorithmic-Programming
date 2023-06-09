//m1
//NOTE: classical problem: weighted / unweighted interval scheduling, dp, or greedy.
//bottom up memo, dp method

#include<algorithm>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

bool cmp_fn(const vector<int>& a, const vector<int>& b){
    //increasing in finish time to get last compatible vector
    return a[1] < b[1];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<int> last_compatible(n);

        sort(intervals.begin(), intervals.end(), cmp_fn);
        for(int i=0;i<n;i++)
            last_compatible[i] = (
                upper_bound(
                    intervals.begin(), 
                    intervals.end(),
                    vector<int>(2, intervals[i][0] ),
                    cmp_fn
                ) -
                intervals.begin()
            ) - 1;
        

        vector<int> memo(n);
        for(int i=0;i<n;i++){
            int last_compat = (last_compatible[i] >= 0)? memo[ last_compatible[i] ]:0;

            memo[i] = max(
                (i-1>=0)? memo[i-1]:0,
                1 + last_compat
            );
        }

        return n - memo[n-1];
    }
};
