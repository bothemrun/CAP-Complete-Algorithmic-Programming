//m2
//NOTE: classical problem: weighted / unweighted interval scheduling, dp, or greedy.

//greedy for unweight interval scheduling: earliest deadline first.
//proof:
// https://www.cs.umd.edu/class/fall2017/cmsc451-0101/Lects/lect07-greedy-sched.pdf

// summary: prove greedy by replacing the optimal choice with the greedy choice, and prove results can only get better (not worse).
// And then apply this argument inductively.

// let j be the first index s.t. optimal & greedy differ.
// optimal = {x[1], ..., x[j-1], x[j], ...}
// greedy =  {x[1], ..., x[j-1], g[j], ...}
// since g[j] chooses the earliest (compatible) deadline, it leaves more room for later intervals,
// so we can replace x[j] with g[j], and results will not get worse / only get better.

// optimal becomes = {x[1], ..., x[j-1], g[j], x[j+1], x[j+2], ...}
// greedy the same = {x[1], ..., x[j-1], g[j], g[j+1], g[j+2], ...}
// since g[j] is the earliest deadline, so no conflict.
//then apply the argument inductively. QED.

#include<algorithm>
#include<limits.h>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

bool cmp_fn(const vector<int>& a, const vector<int>& b){
    return a[1] < b[1];//increasing in deadlines
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end(), cmp_fn);

        int interval_scheduling = 0;
        int finish = INT_MIN;
        for(int i=0;i<n;i++){
            if(finish <= intervals[i][0]){
                interval_scheduling++;
                finish = intervals[i][1];
            }
        }

        return n - interval_scheduling;
    }
};
