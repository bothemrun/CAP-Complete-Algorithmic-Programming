//Thinking Process

//[A] Greedy: earliest deadline first
//1. for a deadline time, look at the available courses with deadlines in this deadline time.
//2. then find smallest duration courses to fit in this deadline time.
//3. like 502. IPO


//[B] Greedy Counterexample:
//1. long 1 + lots of shorts:
//2. (duration, deadline) = (10, 11) + lots of (1, 12)

//[C] Regret Greedy
//1. now with sum of duration of current taken courses := T, current time spent.
//2. now a new course = (len, end)
//3. if T + len > end, we regret greedy
//4. pop the course with longest duration (after pushing this len),
//5. we can make the current time T smaller.
//6. we can always pop a course (may be the new course itself) s.t. new T <= deadline.
//7. since 
//(a)it's the max heap, 
//(b)and the courses in the heap are in their deadlines, 
//(c) deadline input is increasing.


//Regret Greedy, O(nlogn) due to sorting

#include<queue>
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
    int scheduleCourse(vector<vector<int>>& courses) {
        //increasing in deadline.
        auto cmp1 = [](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        };
        sort(courses.begin(), courses.end(), cmp1);

        auto cmp2 = [](const int& a, const int& b){
            return a < b;//max heap for duration
        };
        priority_queue<int, vector<int>, decltype(cmp2) > maxheap(cmp2);


        int cur_time = 0;
        for(const vector<int>& c: courses){
            int duration = c[0];
            int deadline = c[1];

            maxheap.push(duration);
            cur_time += duration;

            if(cur_time > deadline){
                //assert(maxheap.size());
                cur_time -= maxheap.top();
                maxheap.pop();
            }
        }

        return maxheap.size();
    }
};
