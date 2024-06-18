//O(nlogn + mlogm)

#define tii tuple<int, int>
#include<tuple>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = profit.size();
        vector<tii> job(n);
        for(int i=0;i<n;i++)
            job[i] = tii(difficulty[i], profit[i]);
        
        sort(job.begin(), job.end());

        sort(worker.begin(), worker.end());

        int ans = 0;

        int i=0;
        int max_profit = 0;
        for(const int& diff_bound: worker){
            while(i<n && get<0>(job[i]) <= diff_bound ){
                max_profit = max(max_profit, get<1>(job[i++]) );
            }

            ans += max_profit;
        }

        return ans;
    }
};
