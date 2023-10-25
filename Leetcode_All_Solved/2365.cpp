//O(n)
#include<unordered_map>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        long long window = space+1;

        unordered_map<int, long long> type2freeday;
        long long day = 1;
        for(const int& task: tasks){
            if(type2freeday.count(task) && type2freeday[task] > day){
                day = type2freeday[task];
            }

            type2freeday[task] = day + window;
            day++;
        }

        return day-1;
    }
};
