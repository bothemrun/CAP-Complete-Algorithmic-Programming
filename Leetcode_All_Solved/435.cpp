//m0
//NOTE: classical problem: weighted / unweighted interval scheduling, dp, or greedy.
//recursion with memo, dp method

#define notyet (-1)
#include<algorithm>
#include<algorithm>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

bool cmp_fn(const vector<int>& a, const vector<int>& b){
    return a[1] < b[1];//increasing in finish time to find the last compatible vector
}

class Solution {
public:
    vector<int> last_compatible;

    vector<int> memo;
    int choose_or_not(const vector<vector<int>>& intervals, const int& i){
        if(i == 0) return 1;
        if(i < 0) return 0;

        if(memo[i] != notyet) return memo[i];

        return memo[i] = max(
            choose_or_not(intervals, i-1),
            1 + choose_or_not(intervals, last_compatible[i] )
        );
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end(), cmp_fn);

        last_compatible.resize(n);
        //NOTE: find last index s.t. finish[index] <= this start time (== target)
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


        memo.resize(n, notyet);      
        return n - choose_or_not(intervals, n-1);
    }
};
