//m0
//O(n) dp + binary search
//with the overhead of copying 3 array values

#define notyet (-1)
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
    int n;
    vector<vector<int>> job;

    vector<int> next;

    vector<int> memo;

    int suffix_choose_not(const int& i){
        if(i==n) return 0;
        
        if(memo[i] != notyet) return memo[i];

        return memo[i] = max(
            suffix_choose_not(i+1),
            job[i][2] +
            suffix_choose_not(next[i])
        );
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        this->n = profit.size();

        job.resize(n, vector<int>(3));
        for(int i=0;i<n;i++)
            job[i] = vector<int>({ startTime[i], endTime[i], profit[i] });
        
        auto cmp = [](const vector<int>& a, const vector<int>& b){
            return a[0] < b[0];
        };
        sort(job.begin(), job.end(), cmp);


        next.resize(n);
        for(int i=0;i<n;i++){
            int end = job[i][1];

            //NOTE: trick for comparator with multi-dimensional elements.
            int j = lower_bound(job.begin() + i, job.end(), vector<int>({ end, end, end }), cmp) - job.begin();

            next[i] = j;
        }


        memo.resize(n, notyet);
        return suffix_choose_not(0);
    }
};
