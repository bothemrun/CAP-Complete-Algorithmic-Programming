//m1
//O(nlogk), k := number of people
//merge k sorted list, by priority queue

/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

#define PII pair<Interval, int>
#include<queue>
#include<utility>
#include<limits.h>
#include<algorithm>

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {

        auto cmp_lam = [](const PII& a, const PII& b){
            return a.first.start > b.first.start;
            //minheap, sink down
        };
        priority_queue<PII, vector<PII>, decltype(cmp_lam) > minheap(cmp_lam);

        int k = schedule.size();
        for(int i=0;i<k;i++)
            minheap.push( PII( schedule[i][0], i ) );
        
        vector<int> idx(k, 0);


        //merge k sorted list
        vector<Interval> ans;

        int last_end = INT_MIN;
        while(minheap.size()){
            auto [inter, people] = minheap.top();
            minheap.pop();

            idx[people]++;
            if(idx[people] < (int)schedule[people].size() ){
                minheap.push( PII( schedule[people][ idx[people] ], people ) );
            }


            if(last_end < inter.start && last_end != INT_MIN){
                ans.push_back( Interval(last_end, inter.start) );
            }

            last_end = max(last_end, inter.end);
        }

        return ans;
    }
};
